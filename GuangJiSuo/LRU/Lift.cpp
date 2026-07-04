#include "Lift.h"

Lift::Lift(ZMotionControl* zm,dahengTwoCams_qt_vs *dahengCamera,LightSourceController* lightcontrol,QObject *parent) : QObject(parent),
    m_zm(zm),
    m_dahengCamera(dahengCamera),
    m_lightcontroller(lightcontrol)
{
    m_TaskStatus.sys =eSubSystem::Lift;

    //读取ini文件
   iniReadThreshold = new QSettings("param.ini", QSettings::IniFormat);

    //设置 Lift 阈值
   Threshold[0] = iniReadThreshold->value("Lift/ForceXThreshold").toFloat();
   Threshold[1] = iniReadThreshold->value("Lift/ForceYThreshold").toFloat();
   Threshold[2] = iniReadThreshold ->value("Lift/ForceZThreshold").toFloat();
   Threshold[3] = iniReadThreshold ->value("Lift/TorqueXThreshold").toFloat();
   Threshold[4] = iniReadThreshold ->value("Lift/TorqueYThreshold").toFloat();
   Threshold[5] = iniReadThreshold ->value("Lift/TorqueZThreshold").toFloat();

   //视觉加六自由度平台-开始
   m_SixDof = new UdpCommunication(
       "192.168.192.45",   // 上位机IP
       8000,            // 上位机端口
       "192.168.192.88", // 下位机IP
       8080,            // 下位机端口
       2000,              // 接收超时300ms
       this
       );
   m_vision_detected = new ArucoDetector(this);

   // 读取 VisionGeometry 配置
   float markerSizeMm = iniReadThreshold->value("VisionGeometry/MarkerSizeMm", 40.0).toFloat();
   m_vision_detected->setMarkerSizeMm(markerSizeMm);

   // 读取 VisionQuality 配置
   m_cfgFrameCount = iniReadThreshold->value("VisionQuality/FrameCount", 15).toInt();
   m_cfgMinValidFrames = iniReadThreshold->value("VisionQuality/MinValidFrames", 8).toInt();
   m_cfgBatchRetryCount = iniReadThreshold->value("VisionQuality/BatchRetryCount", 1).toInt();
   m_cfgReprojectionErrorMaxPx = iniReadThreshold->value("VisionQuality/ReprojectionErrorMaxPx", 2.5).toDouble();
   m_cfgCornerBorderMarginPx = iniReadThreshold->value("VisionQuality/CornerBorderMarginPx", 5).toInt();
   m_cfgJumpXyMm = iniReadThreshold->value("VisionQuality/JumpXyMm", 2.0).toDouble();
   m_cfgJumpYawDeg = iniReadThreshold->value("VisionQuality/JumpYawDeg", 1.0).toDouble();
   m_vision_detected->setCornerBorderMarginPx(m_cfgCornerBorderMarginPx);

   // 读取 AutoLiftControl 配置
   m_cfgSettleXyMm = iniReadThreshold->value("AutoLiftControl/SettleXyMm", 0.15).toDouble();
   m_cfgSettleYawDeg = iniReadThreshold->value("AutoLiftControl/SettleYawDeg", 0.15).toDouble();
   m_cfgStablePassCount = iniReadThreshold->value("AutoLiftControl/StablePassCount", 2).toInt();
   m_cfgMaxCorrections = iniReadThreshold->value("AutoLiftControl/MaxCorrectionCommandsPerHeight", 5).toInt();
   m_cfgCorrectionGain = iniReadThreshold->value("AutoLiftControl/CorrectionGain", 0.70).toDouble();
   m_cfgResidualGrowthStopRatio = iniReadThreshold->value("AutoLiftControl/ResidualGrowthStopRatio", 1.10).toDouble();
   m_cfgCrossHeightXyMm = iniReadThreshold->value("AutoLiftControl/CrossHeightXyMm", 1.5).toDouble();
   m_cfgCrossHeightYawDeg = iniReadThreshold->value("AutoLiftControl/CrossHeightYawDeg", 0.3).toDouble();

   autolift = false;
   autodescent = false;
   m_angle = 0.0;
   m_gapwidth_x = 0.0;
   m_gapwidth_y = 0.0;

   x_gap_lift = 0.0f;
   y_gap_lift = 0.0f;
   final_z_lift = 0.0f;
   //视觉加六自由度平台-结束


   m_statusMonitorTimer = new QTimer(this);//电机状态检测判定系统任务状态
   connect(m_statusMonitorTimer, &QTimer::timeout, this, &Lift::monitorSubsystemStatus);
   UpTimer = new QTimer(this);
   DownTimer = new QTimer(this);

   // 采集电流数据写入数据库
   m_currentCollectionTimer = new QTimer(this);
   connect(m_currentCollectionTimer, &QTimer::timeout, this, &Lift::collectMotorCurrents);
   m_currentCollectionTimer->start(300);
}


// 定时将电机电流写入数据库
void Lift::collectMotorCurrents()
{
    // 系统运行时才采集电流
    if (m_currentState == eTaskstate::Running) {
        for(int i = 5;i < 12 ;i++){
            float current = m_zm->GetMotorCurrent(i);
            QString sensorType = QString("电流-电机%1").arg(i);
            DatabaseManager::getInstance()->logSensorData(sensorType, current);
        }
    }
}

// 获取子系统实时状态  电机12
void Lift::getSubSystemState()
{
    //检查是否处于错误状态
    m_errorInfo.clear();
    if (m_zm->GetAxisStatus(12) != MyAxisSatus::正常状态) {
        // if(!m_errorInfo.isEmpty())
        // {
        //     m_errorInfo += "\n";
        // }
        m_errorInfo += QString("轴 %1 错误 : %2").arg(12).arg(AxisStatusQstr(m_zm->GetAxisStatus(12)));
        m_currentState = eTaskstate::Error;
        return;
    }

    //Running状态
    if (m_zm->GetAxisMType(12) != AxisMType::Idle) {
        m_currentState = eTaskstate::Running;
        return;
    }

    // 全部轴静止，触发标志位为Complete状态，未触发且为正常状态为ready状态
    // IsSingleIdle 获取轴运动状态，0运行中，1运动停止
    if (m_zm->GetAxisMType(12) == AxisMType::Idle) {
        if (m_isHalfAutoLiftUp || m_isAutoLiftDown) {
            m_currentState = eTaskstate::Complete;
            QTimer::singleShot(400, this, [=]() {
            m_statusMonitorTimer->stop();
            m_isHalfAutoLiftUp = false;   //自动模式下，判定任务完成后已经进入下一个系统动作，此处重置自动标志位；
            m_isAutoLiftDown = false;});
            return;
        }
        else{
            m_currentState = eTaskstate::Ready;
            return;
        }
    }
}

// 处理状态转换
void Lift::handleStateTransition(eTaskstate newState)
{
    bool StatusChange = false;

    if (m_lastState!= newState) StatusChange = true;

    if(newState == eTaskstate::Error && m_lastState == eTaskstate::Error){
        if(m_TaskStatus.info != m_errorInfo) StatusChange = true;
    }

    if(newState != eTaskstate::Error && m_lastState == eTaskstate::Error){
        emit UpdateSystemInfo("报错已解决!");
    }

    if(StatusChange)
    {
        m_lastState = newState;

        //进入新状态，清除错误信息
        m_TaskStatus.info.clear();

        // 计算耗时
        if (newState == eTaskstate::Complete || newState == eTaskstate::Error) {
            double elapsed = m_taskStartTime.msecsTo(QDateTime::currentDateTime()) / 1000.0;
            m_TaskStatus.duration = elapsed;
        }

        // 更新任务状态
        switch (newState) {
        case eTaskstate::Ready:
            m_TaskStatus.state = eTaskstate::Ready;
            break;
        case eTaskstate::Running:
            m_TaskStatus.state = eTaskstate::Running;
            break;
        case eTaskstate::Complete:
            m_TaskStatus.state = eTaskstate::Complete;
            break;
        case eTaskstate::Error:
            m_TaskStatus.state = eTaskstate::Error;
            m_TaskStatus.info = m_errorInfo; // 设置错误信息
            break;
        case nsTaskMgr::eTaskstate::Init:
            break;
        }

        emit sigStatusFeedback(m_TaskStatus);
    }
}

// 状态监测定时器回调
void Lift::monitorSubsystemStatus()
{
    getSubSystemState();
    handleStateTransition(m_currentState);
}


//二级升降为手动操作_测试用
void Lift::ExeLiftTask(TaskInfo info)
{
    QMessageBox::information(nullptr, "提示", "取盖板任务完成，请手动操作二级升降系统！");
}

//正向任务，二级升降改为手动操作，这里暂时不用
void Lift::ExeLiftTask1()
{
    m_statusMonitorTimer->start(200);//开启状态监测定时器

    m_taskStartTime = QDateTime::currentDateTime();  // 记录任务开始时间

    autolift = true;//开始自动抬升
    auto_lift();
    connect(UpTimer,&QTimer::timeout,this,[=](){
        if(abs(m_zm->myZmotionStatus->allAxisStatus[12].posi - 1400) < 0.1){
            autolift = false;
            m_isHalfAutoLiftUp = true;
            UpTimer->stop();
        }
    });
}

//反向任务，二级升降改为手动操作，这里暂时不用
void Lift::ExeLiftTask2()
{
    m_statusMonitorTimer->start(200);//开启状态监测定时器

    m_taskStartTime = QDateTime::currentDateTime();  // 记录任务开始时间

    m_zm->MoveSingleAbs(12,0);
    DownTimer->start(200);
    connect(DownTimer,&QTimer::timeout,this,[=](){
        if(abs(m_zm->myZmotionStatus->allAxisStatus[12].posi) < 0.1){
            m_isAutoLiftDown = true;
            DownTimer->stop();
        }
    });
}


//手动接管逻辑是由自动模式跳转的，此时任务类型已经确定
//暂不用
void Lift::IsManualLift()
{
    m_statusMonitorTimer->start(200);

    QTimer* myTimer = new QTimer(this);

    if (m_TaskStatus.taskinfo.TaskType == 1)
    {
        connect(myTimer,&QTimer::timeout,this,[=](){
            if(abs(m_zm->myZmotionStatus->allAxisStatus[12].posi - 1400) < 0.1){
                m_isManualLiftUp = true;
                myTimer->stop();
                QMessageBox::information(nullptr, "提示", "可恢复自动调度！");
            }
            else{
                QMessageBox::warning(nullptr, "警告", "二级未抬升到位！");
            }
        });
    }
    else if(m_TaskStatus.taskinfo.TaskType == 2)
    {
        connect(myTimer,&QTimer::timeout,this,[=](){
            if(abs(m_zm->myZmotionStatus->allAxisStatus[12].posi) < 0.1){
                m_isManualLiftDown = true;
                myTimer->stop();
                QMessageBox::information(nullptr, "提示", "可恢复自动调度！");
            }
            else{
                 QMessageBox::warning(nullptr, "警告", "二级未下降到位！");
            }
        });
    }
}

//获取六维力信息，进行碰撞检测
void Lift::CheckCollision()
{
    isforceOver = false;
    overflowInfo.clear();
    for(int i = 0; i < 6; i++)
    {
        if(fabs(Check_ForceInfo[i]) > 100)
        {
            if(!overflowInfo.isEmpty()){
                overflowInfo += ",";
            }
            overflowInfo += axisNames[i] + "超出阈值";
            isforceOver = true;
        }
    }

    if (isforceOver)
    {
        // 停止二级升降
        emit isCollision(true,overflowInfo);
        m_zm->SingleVMove(12,Cancel);
        stop_auto_lift();
    }
    else
    {
        //如果未碰撞就把当前的实时信息更新为碰撞前的信息
        memcpy(LastCheck_ForceInfo, Check_ForceInfo, sizeof(Check_ForceInfo));
        emit isCollision(false,"");
    }
}



//分离检测逻辑
void Lift::CheckDetach()
{
    if(m_isDetectingDetach)
    {
        return;
    }

    // 开始执行脱离检测，防止重复创建定时器
    m_isDetectingDetach = true;

    float pos1 = m_zm->GetAxisDpos(12);
    QTimer::singleShot(200,this,[=](){
        float pos2 = m_zm->GetAxisDpos(12);

        //下降过程再判断是否脱离
        if(pos2 - pos1 < -1){
            if(isFirstLowering){
                QTimer::singleShot(1000,this,[this](){
                    float currentFz = Check_ForceInfo[2];
                    float lastFz = LastCheck_ForceInfo[2];
                    if(currentFz - lastFz < -150){//阈值需要调节
                        emit isDetach(true);
                        isFirstLowering = false;//已脱离，确保只判断一次
                    }
                    else{
                        emit isDetach(false);
                        m_zm->EmergencyStop();
                    }
                    // 释放标记，允许下一次检测
                    m_isDetectingDetach = false;
                });
            }
        }
        else{//静止或上升
            isFirstLowering = true;//重置标志
            m_isDetectingDetach = false;
        }
    });
}


//信息交互
void Lift::SetForceData(SixForeData* data)
{
    Check_ForceInfo[0] = data->Fx;
    Check_ForceInfo[1] = data->Fy;
    Check_ForceInfo[2] = data->Fz;
    Check_ForceInfo[3] = data->Mx;
    Check_ForceInfo[4] = data->My;
    Check_ForceInfo[5] = data->Mz;
}

//视觉加六自由度平台-开始
bool Lift::StatusModifyLatte()
{
    if(checkCollision_flag == false)
    {
        LiftUpdateUI("请先开启碰撞检测!");
        return false;
    }
    if(detected_flag == false)
    {
        LiftUpdateUI("请先进行视觉检测!");
        return false;
    }
    if(autodescent || autolift)
    {
        LiftUpdateUI("自动运动中，请勿手动调整");
        return false;
    }

    QJsonObject coordinates = m_SixDof->getCurrentCoordinates();

    float x  = QString::number(coordinates["x"].toDouble(),  'f', 2).toFloat();
    float y  = QString::number(coordinates["y"].toDouble(),  'f', 2).toFloat();
    float z  = QString::number(coordinates["z"].toDouble(),  'f', 2).toFloat();
    float rx = QString::number(coordinates["rx"].toDouble(), 'f', 2).toFloat();
    float ry = QString::number(coordinates["ry"].toDouble(), 'f', 2).toFloat();
    float rz = QString::number(coordinates["rz"].toDouble(), 'f', 2).toFloat();

    float angle = 0.0;
    float distance_x = 0.0;
    float distance_y = 0.0;

    angle = m_angle;
    distance_x = m_gapwidth_x;
    distance_y = m_gapwidth_y;

    // 如果编译器不支持M_PI，可以使用std::acos(-1)代替：
    float rz_rad = std::abs(rz) * (std::acos(-1) / 180.0);

    float goal_distance_x = (distance_x - x_gap_lift) * std::cos(rz_rad);

    float goal_distance_y = (distance_y - y_gap_lift) * std::cos(rz_rad);


    if( angle <= -0.15 || angle >= 0.15)
    {
        m_SixDof->posePointMotion(x, y, z, rx, ry, rz-angle,2,1);
        LiftUpdateUI("六自由度平台正在调整");
    }
    else if(goal_distance_x > 0.15 || goal_distance_x < -0.15 || goal_distance_y > 0.15 || goal_distance_y < -0.15)
    {
        m_SixDof->posePointMotion(x+goal_distance_x, y-goal_distance_y, z, rx, ry, rz,2,1);
        LiftUpdateUI("六自由度平台正在调整");
    }
    else
    {
        LiftUpdateUI("六自由度平台不需要调整");
    }
    detected_flag = false;
    return true;
}

bool Lift::vision_detected()
{
    if(!m_zm->GetConnectStatus())
    {
        LiftUpdateUI("未连接控制器");
        return false;
    }
    float z = 0.0;
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    emit sendBrightnessValueToMainWindow(255);
    if(z<-1.0)
    {
        LiftUpdateUI("二级高度值获取错误");
        return false;
    }
    QThread::sleep(1);
    if(!m_dahengCamera)
    {
        LiftUpdateUI("相机对象失效");
        return false;
    }
    if(autodescent || autolift)
    {
        LiftUpdateUI("自动运动中，请勿手动检测");
        return false;
    }

    QJsonObject coordinates = m_SixDof->getCurrentCoordinates();
    float six_z  = QString::number(coordinates["z"].toDouble(),  'f', 2).toFloat();

    int deviceIndex = -1;
    if((-0.5<=z && z<=0.5) && (-1.0<=six_z && six_z<=1.0))
        deviceIndex = 1;
    else if((1699.5<=z && z<=1700.5) && (-1.0<=six_z && six_z<=1.0))
        deviceIndex = 0;

    if (deviceIndex < 0) {
        LiftUpdateUI("二级或者六自由度不在工作距离，无法检测");
        return false;
    }

    // 多帧检测（手动也使用同一套标准）
    MultiFrameResult mfr = detectMultiFrame(deviceIndex);
    if (!mfr.valid) {
        softStop(mfr.failureReason, mfr.validFrameCount, m_cfgFrameCount);
        return false;
    }

    m_angle = mfr.yaw;
    m_gapwidth_x = mfr.x;
    m_gapwidth_y = mfr.y;

    nsTaskMgr::DetectedDisplayData vision_data;
    vision_data.angle = m_angle;
    vision_data.rho1 = m_gapwidth_x;
    vision_data.rho2 = m_gapwidth_y;
    emit lift_updateGapInfo(vision_data);
    detected_flag = true;
    LiftUpdateUI("多帧视觉检测完成");
    return true;
}


bool Lift::auto_lift()
{
    if(!m_zm->GetConnectStatus())
    {
        LiftUpdateUI("未连接控制器");
        qInfo()<<"未连接控制器";
        return false;
    }
    if(checkCollision_flag == false)
    {
        LiftUpdateUI("请先开启碰撞检测!");
        return false;
    }
    if(autodescent)
    {
        LiftUpdateUI("正在下降中！不能抬升");
        return false;
    }

    float goal_z = final_z_lift;
    float z = 0.0;

    // ================================================================
    //  阶段1：z≈0，相机1 — 多帧检测 + 补偿闭环
    // ================================================================
    int corrections = 0;
    int stableCount = 0;
    float z0ResX = 0, z0ResY = 0, z0ResYaw = 0;
    bool z0Stable = false;

    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    if(z >= -0.5f && z < 0.5f && autolift)
    {
        while(corrections <= m_cfgMaxCorrections && autolift)
        {
            LiftUpdateUI("z≈0: 多帧检测");
            MultiFrameResult mfr = detectMultiFrame(1);
            if(!mfr.valid)
            {
                softStop(mfr.failureReason, mfr.validFrameCount, m_cfgFrameCount);
                return false;
            }

            float xRes = mfr.x - x_gap_lift;
            float yRes = mfr.y - y_gap_lift;
            float yawRes = mfr.yaw;

            if(qAbs(xRes) <= m_cfgSettleXyMm && qAbs(yRes) <= m_cfgSettleXyMm && qAbs(yawRes) <= m_cfgSettleYawDeg)
            {
                stableCount++;
                LiftUpdateUI(QString("z≈0: 稳定%1/%2").arg(stableCount).arg(m_cfgStablePassCount));
                if(stableCount >= m_cfgStablePassCount)
                {
                    z0ResX = xRes; z0ResY = yRes; z0ResYaw = yawRes;
                    z0Stable = true;
                    LiftUpdateUI("z≈0: 已稳定");
                    break;
                }
                QThread::msleep(200);
                continue;
            }
            stableCount = 0;

            double oldScore = residualScore(xRes, yRes, yawRes);

            QJsonObject coords = m_SixDof->getCurrentCoordinates();
            float cx  = QString::number(coords["x"].toDouble(),  'f', 2).toFloat();
            float cy  = QString::number(coords["y"].toDouble(),  'f', 2).toFloat();
            float cz  = QString::number(coords["z"].toDouble(),  'f', 2).toFloat();
            float crx = QString::number(coords["rx"].toDouble(), 'f', 2).toFloat();
            float cry = QString::number(coords["ry"].toDouble(), 'f', 2).toFloat();
            float crz = QString::number(coords["rz"].toDouble(), 'f', 2).toFloat();

            if(qAbs(yawRes) > m_cfgSettleYawDeg)
            {
                m_SixDof->posePointMotion(cx, cy, cz, crx, cry, crz - yawRes * m_cfgCorrectionGain, 2, 1);
            }
            else
            {
                float rz_rad = std::abs(crz) * (std::acos(-1) / 180.0);
                float goalX = (mfr.x - x_gap_lift) * std::cos(rz_rad) * m_cfgCorrectionGain;
                float goalY = (mfr.y - y_gap_lift) * std::cos(rz_rad) * m_cfgCorrectionGain;
                m_SixDof->posePointMotion(cx + goalX, cy - goalY, cz, crx, cry, crz, 2, 1);
            }
            waitSixDof();

            MultiFrameResult postMfr = detectMultiFrame(1);
            if(!postMfr.valid)
            {
                softStop("补偿后复测失败", postMfr.validFrameCount, m_cfgFrameCount, xRes, yRes, yawRes);
                return false;
            }
            double postScore = residualScore(postMfr.x - x_gap_lift, postMfr.y - y_gap_lift, postMfr.yaw);
            if(postScore > oldScore * m_cfgResidualGrowthStopRatio)
            {
                softStop(QString("补偿后残差增大: score %1→%2").arg(oldScore,0,'f',2).arg(postScore,0,'f',2),
                         0,0,xRes,yRes,yawRes);
                return false;
            }
            corrections++;
        }
        if(!z0Stable)
        {
            softStop(QString("z=0 未能稳定，已补偿%1次").arg(corrections));
            return false;
        }
    }

    // ================================================================
    //  升到 z≈1700
    // ================================================================
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    if(z < 1700)
    {
        LiftUpdateUI("二级抬升至1700mm");
        m_zm->MoveSingleAbs(12, 1700);
        QThread::msleep(200);
        while(!m_zm->IsSingleIdle(12))
        {
            if(!autolift) { LiftUpdateUI("自动抬升已终止"); return false; }
            QThread::msleep(100);
        }
    }

    // ================================================================
    //  阶段2：z≈1700，相机0 — 同理闭环
    // ================================================================
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    corrections = 0;
    stableCount = 0;
    float z1700ResX = 0, z1700ResY = 0, z1700ResYaw = 0;
    bool z1700Stable = false;

    if(z > 1699.5f && z < 1700.5f && autolift)
    {
        while(corrections <= m_cfgMaxCorrections && autolift)
        {
            LiftUpdateUI("z≈1700: 多帧检测");
            MultiFrameResult mfr = detectMultiFrame(0);
            if(!mfr.valid)
            {
                softStop(mfr.failureReason, mfr.validFrameCount, m_cfgFrameCount);
                return false;
            }

            float xRes = mfr.x - x_gap_lift;
            float yRes = mfr.y - y_gap_lift;
            float yawRes = mfr.yaw;

            if(qAbs(xRes) <= m_cfgSettleXyMm && qAbs(yRes) <= m_cfgSettleXyMm && qAbs(yawRes) <= m_cfgSettleYawDeg)
            {
                stableCount++;
                if(stableCount >= m_cfgStablePassCount)
                {
                    z1700ResX = xRes; z1700ResY = yRes; z1700ResYaw = yawRes;
                    z1700Stable = true;
                    LiftUpdateUI("z≈1700: 已稳定");
                    break;
                }
                QThread::msleep(200);
                continue;
            }
            stableCount = 0;

            double oldScore = residualScore(xRes, yRes, yawRes);

            QJsonObject coords = m_SixDof->getCurrentCoordinates();
            float cx  = QString::number(coords["x"].toDouble(),  'f', 2).toFloat();
            float cy  = QString::number(coords["y"].toDouble(),  'f', 2).toFloat();
            float cz  = QString::number(coords["z"].toDouble(),  'f', 2).toFloat();
            float crx = QString::number(coords["rx"].toDouble(), 'f', 2).toFloat();
            float cry = QString::number(coords["ry"].toDouble(), 'f', 2).toFloat();
            float crz = QString::number(coords["rz"].toDouble(), 'f', 2).toFloat();

            if(qAbs(yawRes) > m_cfgSettleYawDeg)
            {
                m_SixDof->posePointMotion(cx, cy, cz, crx, cry, crz - yawRes * m_cfgCorrectionGain, 2, 1);
            }
            else
            {
                float rz_rad = std::abs(crz) * (std::acos(-1) / 180.0);
                float goalX = (mfr.x - x_gap_lift) * std::cos(rz_rad) * m_cfgCorrectionGain;
                float goalY = (mfr.y - y_gap_lift) * std::cos(rz_rad) * m_cfgCorrectionGain;
                m_SixDof->posePointMotion(cx + goalX, cy - goalY, cz, crx, cry, crz, 2, 1);
            }
            waitSixDof();

            MultiFrameResult postMfr = detectMultiFrame(0);
            if(!postMfr.valid)
            {
                softStop("补偿后复测失败", postMfr.validFrameCount, m_cfgFrameCount, xRes, yRes, yawRes);
                return false;
            }
            double postScore = residualScore(postMfr.x - x_gap_lift, postMfr.y - y_gap_lift, postMfr.yaw);
            if(postScore > oldScore * m_cfgResidualGrowthStopRatio)
            {
                softStop(QString("补偿后残差增大: score %1→%2").arg(oldScore,0,'f',2).arg(postScore,0,'f',2),
                         0,0,xRes,yRes,yawRes);
                return false;
            }
            corrections++;
        }

        if(!z1700Stable)
        {
            softStop(QString("z=1700 未能稳定，已补偿%1次").arg(corrections));
            return false;
        }

        // 跨高度一致性检查
        if(qAbs(z1700ResX - z0ResX) > m_cfgCrossHeightXyMm ||
           qAbs(z1700ResY - z0ResY) > m_cfgCrossHeightXyMm ||
           qAbs(z1700ResYaw - z0ResYaw) > m_cfgCrossHeightYawDeg)
        {
            softStop(QString("跨高度残差不一致: z0(x=%1,y=%2,yaw=%3) z1700(x=%4,y=%5,yaw=%6)")
                         .arg(z0ResX,0,'f',3).arg(z0ResY,0,'f',3).arg(z0ResYaw,0,'f',3)
                         .arg(z1700ResX,0,'f',3).arg(z1700ResY,0,'f',3).arg(z1700ResYaw,0,'f',3));
            return false;
        }
        LiftUpdateUI("跨高度残差一致");
    }

    // ================================================================
    //  升到 final_z_lift
    // ================================================================
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    if(1700 <= z)
    {
        LiftUpdateUI("二级抬升到最终高度");
        m_zm->MoveSingleAbs(12, goal_z);
        QThread::msleep(200);
        while(!m_zm->IsSingleIdle(12))
        {
            if(!autolift) { LiftUpdateUI("自动抬升已终止"); return false; }
            QThread::msleep(100);
        }
    }

    QThread::msleep(500);
    QJsonObject coordinates = m_SixDof->getCurrentCoordinates();
    float six_x = QString::number(coordinates["x"].toDouble(), 'f', 2).toFloat();
    float six_y = QString::number(coordinates["y"].toDouble(), 'f', 2).toFloat();
    emit sigAutoLiftFinalSixDofCoordinates(six_x, six_y);
    autolift = false;
    LiftUpdateUI("自动抬升运动完成");
    return true;
}

bool Lift::auto_descent()
{
    if(!m_zm->GetConnectStatus())
    {
        LiftUpdateUI("未连接控制器");
        qInfo()<<"未连接控制器";
        return false;
    }
    if(checkCollision_flag == false)
    {
        LiftUpdateUI("请先开启碰撞检测!");
        return false;
    }

    if(autolift)
    {
        LiftUpdateUI("正在抬升中！不能下降");
        return false;
    }
    int i = 0;
    float z = 0.0;
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;

    if(z > 1700 && autodescent)
    {
        LiftUpdateUI("二级下降中");
        m_zm->MoveSingleAbs(12,1700);
        QThread::msleep(200);
        while(!(m_zm->IsSingleIdle(12)))
        {
            if(!autodescent)
            {
                LiftUpdateUI("自动下降已终止");
                return false;
            }
            QThread::msleep(100);
        }
    }
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;

    if(z > 1699.5f && z < 1700.5f && autodescent)
    {
        while(i<=3 && autodescent)
        {
            LiftUpdateUI("正在检测缝隙");
            QThread::msleep(100);
            detected_flag = auto_vision_detected();
            if(detected_flag == false)
            {
                LiftUpdateUI("视觉检测失败，自动抬升已终止");
                return false;
            }
            LiftUpdateUI("正在进行姿态调整");
            if(!autodescent)
            {
                LiftUpdateUI("自动抬升已终止");
                return false;
            }
            bool flag = auto_StatusModifyLatte();
            if(flag == false)
            {
                LiftUpdateUI("平台运动失败，自动抬升已终止");
                return false;
            }
            waitSixDof();
            LiftUpdateUI("六自由度平台调整已完成");
            i++;
        }
    }
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;

    if(z <= 1700 && autodescent)
    {
        LiftUpdateUI("二级下降中");
        m_zm->MoveSingleAbs(12,0);
        QThread::msleep(200);
        while(!(m_zm->IsSingleIdle(12)))
        {
            if(!autodescent)
            {
                LiftUpdateUI("自动下降已终止");
                return false;
            }
            QThread::msleep(100);
        }
    }
    autodescent = false;
    LiftUpdateUI("自动下降运动完成");
    return true;
}

void Lift::stop_auto_lift()
{
    m_SixDof->stopMotion();
    if(!m_zm->GetConnectStatus())
    {
        LiftUpdateUI("未连接控制器");
        qInfo()<<"未连接控制器";
        return;
    }
    autolift = false;
    autodescent = false;
    m_zm->EmergencyStop();
    m_SixDof->stopMotion();
    m_zm->EmergencyStop();
}

void Lift::waitSixDof()
{
    QThread::msleep(300);
    while(m_SixDof->isPlatformMoving() && (autolift || autodescent))
    {
        LiftUpdateUI("等待六自由度");
        QThread::msleep(100);
    }
}

// =============================================================================
//    多帧检测 helper
// =============================================================================
Lift::MultiFrameResult Lift::detectMultiFrame(int deviceIndex)
{
    MultiFrameResult mfr;

    int exposureUs = m_dahengCamera->getExposureTimeUs(deviceIndex);
    int timeoutMs = qMax(1000, 2 * (exposureUs / 1000) + 200);

    int consecutiveRetries = 0;
    const int maxRetries = m_cfgBatchRetryCount;

    while (consecutiveRetries <= maxRetries) {
        QVector<double> xs, ys, yaws;
        int collectedFrames = 0;
        int64_t lastSeq = -1;

        for (int i = 0; i < m_cfgFrameCount; ++i) {
            auto [mat, seq] = m_dahengCamera->getlatestframeWithSeq(deviceIndex);
            if (mat.empty()) continue;

            // 等待新帧
            QElapsedTimer timer;
            timer.start();
            while (seq == lastSeq && timer.elapsed() < timeoutMs) {
                QThread::msleep(5);
                auto [newMat, newSeq] = m_dahengCamera->getlatestframeWithSeq(deviceIndex);
                if (!newMat.empty() && newSeq != lastSeq) {
                    mat = newMat;
                    seq = newSeq;
                    break;
                }
            }
            if (seq == lastSeq) continue;
            lastSeq = seq;

            float z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
            ArucoDetector::DetailedFrameResult frameResult =
                m_vision_detected->processImageDetailed(mat, z);
            if (!frameResult.valid) continue;

            xs.push_back(frameResult.x);
            ys.push_back(frameResult.y);
            yaws.push_back(frameResult.yaw);
            collectedFrames++;
        }

        if (collectedFrames < m_cfgMinValidFrames) {
            LiftUpdateUI(QString("有效帧不足: %1/%2").arg(collectedFrames).arg(m_cfgMinValidFrames));
            consecutiveRetries++;
            continue;
        }

        auto median = [](QVector<double> &v) -> double {
            if (v.isEmpty()) return 0.0;
            std::sort(v.begin(), v.end());
            return v[v.size() / 2];
        };
        double medX = median(xs), medY = median(ys), medYaw = median(yaws);

        // 剔除跳变帧
        QVector<double> fxs, fys, fyaws;
        for (int i = 0; i < collectedFrames; ++i) {
            if (std::abs(xs[i] - medX) <= m_cfgJumpXyMm &&
                std::abs(ys[i] - medY) <= m_cfgJumpXyMm &&
                std::abs(yaws[i] - medYaw) <= m_cfgJumpYawDeg) {
                fxs.push_back(xs[i]);
                fys.push_back(ys[i]);
                fyaws.push_back(yaws[i]);
            }
        }

        int filteredCount = fxs.size();
        if (filteredCount < m_cfgMinValidFrames) {
            LiftUpdateUI(QString("剔除跳变后有效帧不足: %1/%2").arg(filteredCount).arg(m_cfgMinValidFrames));
            consecutiveRetries++;
            continue;
        }

        mfr.x = median(fxs);
        mfr.y = median(fys);
        mfr.yaw = median(fyaws);
        mfr.validFrameCount = filteredCount;
        mfr.valid = true;

        LiftUpdateUI(QString("多帧检测成功: 有效帧%1/%2, x=%3 y=%4 yaw=%5")
                         .arg(filteredCount).arg(m_cfgFrameCount)
                         .arg(mfr.x, 0, 'f', 3).arg(mfr.y, 0, 'f', 3).arg(mfr.yaw, 0, 'f', 3));
        return mfr;
    }

    mfr.failureReason = QString("多帧检测失败，重试%1次后仍然无效").arg(maxRetries);
    LiftUpdateUI(mfr.failureReason);
    return mfr;
}

// =============================================================================
//    残差评分
// =============================================================================
double Lift::residualScore(double xRes, double yRes, double yawRes)
{
    double sx = qAbs(m_cfgSettleXyMm > 0.001 ? xRes / m_cfgSettleXyMm : 0.0);
    double sy = qAbs(m_cfgSettleXyMm > 0.001 ? yRes / m_cfgSettleXyMm : 0.0);
    double syaw = qAbs(m_cfgSettleYawDeg > 0.001 ? yawRes / m_cfgSettleYawDeg : 0.0);
    return qMax(sx, qMax(sy, syaw));
}

// =============================================================================
//    软停止（不调用 EmergencyStop）
// =============================================================================
void Lift::softStop(const QString& reason, int validFrames, int totalFrames,
                     double xRes, double yRes, double yawRes)
{
    autolift = false;
    detected_flag = false;
    m_SixDof->stopMotion();

    if (!m_zm->IsSingleIdle(12)) {
        m_zm->SingleVMove(12, Cancel);
    }

    QString msg = reason;
    if (totalFrames > 0) {
        msg += QString(" | 采样%1帧, 有效%2帧").arg(totalFrames).arg(validFrames);
    }
    msg += QString(" | 残差 x=%1 y=%2 yaw=%3")
               .arg(xRes, 0, 'f', 3).arg(yRes, 0, 'f', 3).arg(yawRes, 0, 'f', 3);
    msg += " | 建议：检查遮挡/反光/光源/相机标定后手动处理";

    LiftUpdateUI(msg);
    emit UpdateSystemInfo(msg);
    qInfo() << "softStop:" << msg;
}

void Lift::onParamsReceived(const LRUInnerParams &params)
{
    x_gap_lift = params.x_gap;
    y_gap_lift = params.y_gap;
    final_z_lift = params.final_z;
    m_SixDof->target_rx = params.target_rx;
    m_SixDof->target_ry = params.target_ry;
}

void Lift::setcollisionState(bool newState)
{
    if (checkCollision_flag != newState) {
        checkCollision_flag = newState;
    }
}



bool Lift::auto_vision_detected()
{
    if(!m_zm->GetConnectStatus())
    {
        LiftUpdateUI("未连接控制器");
        return false;
    }
    float z = 0.0;
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    emit sendBrightnessValueToMainWindow(255);
    if(z<-1.0)
    {
        LiftUpdateUI("二级高度值获取错误");
        return false;
    }
    QThread::sleep(1);
    if(!m_dahengCamera)
    {
        LiftUpdateUI("相机对象失效");
        return false;
    }
    QJsonObject coordinates = m_SixDof->getCurrentCoordinates();
    float six_z  = QString::number(coordinates["z"].toDouble(),  'f', 2).toFloat();

    // 选择设备索引
    int deviceIndex = -1;
    if((-0.5<=z && z<=0.5) && (-1.0<=six_z && six_z<=1.0))
        deviceIndex = 1;
    else if((1699.5<=z && z<=1700.5) && (-1.0<=six_z && six_z<=1.0))
        deviceIndex = 0;

    if (deviceIndex < 0) {
        LiftUpdateUI("二级或者六自由度不在工作距离，无法检测");
        return false;
    }

    // 多帧检测
    MultiFrameResult mfr = detectMultiFrame(deviceIndex);
    if (!mfr.valid) {
        softStop(mfr.failureReason, mfr.validFrameCount, m_cfgFrameCount);
        return false;
    }

    m_angle = mfr.yaw;
    m_gapwidth_x = mfr.x;
    m_gapwidth_y = mfr.y;

    nsTaskMgr::DetectedDisplayData vision_data;
    vision_data.angle = m_angle;
    vision_data.rho1 = m_gapwidth_x;
    vision_data.rho2 = m_gapwidth_y;
    emit lift_updateGapInfo(vision_data);
    detected_flag = true;
    LiftUpdateUI("多帧视觉检测完成");
    return true;
}

bool Lift::auto_StatusModifyLatte()
{
    if(checkCollision_flag == false)
    {
        LiftUpdateUI("请先开启碰撞检测!");
        return false;
    }
    if(detected_flag == false)
    {
        LiftUpdateUI("请先进行视觉检测!");
        return false;
    }
    LiftUpdateUI("六自由度平台正在调整");
    QJsonObject coordinates = m_SixDof->getCurrentCoordinates();

    float x  = QString::number(coordinates["x"].toDouble(),  'f', 2).toFloat();
    float y  = QString::number(coordinates["y"].toDouble(),  'f', 2).toFloat();
    float z  = QString::number(coordinates["z"].toDouble(),  'f', 2).toFloat();
    float rx = QString::number(coordinates["rx"].toDouble(), 'f', 2).toFloat();
    float ry = QString::number(coordinates["ry"].toDouble(), 'f', 2).toFloat();
    float rz = QString::number(coordinates["rz"].toDouble(), 'f', 2).toFloat();

    float angle = m_angle;
    float distance_x = m_gapwidth_x;
    float distance_y = m_gapwidth_y;

    float rz_rad = std::abs(rz) * (std::acos(-1) / 180.0);

    // 70% 增益补偿
    float goal_distance_x = (distance_x - x_gap_lift) * std::cos(rz_rad) * m_cfgCorrectionGain;
    float goal_distance_y = (distance_y - y_gap_lift) * std::cos(rz_rad) * m_cfgCorrectionGain;

    if( angle <= -m_cfgSettleYawDeg || angle >= m_cfgSettleYawDeg)
    {
        m_SixDof->posePointMotion(x, y, z, rx, ry, rz - angle * m_cfgCorrectionGain, 2, 1);
        LiftUpdateUI("六自由度平台正在调整");
    }
    else if(goal_distance_x > m_cfgSettleXyMm || goal_distance_x < -m_cfgSettleXyMm ||
            goal_distance_y > m_cfgSettleXyMm || goal_distance_y < -m_cfgSettleXyMm)
    {
        m_SixDof->posePointMotion(x + goal_distance_x, y - goal_distance_y, z, rx, ry, rz, 2, 1);
        LiftUpdateUI("六自由度平台正在调整");
    }
    else{
        LiftUpdateUI("六自由度平台不需要调整");
    }
    detected_flag = false;
    return true;
}
//视觉加六自由度平台-结束
