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
   m_vision_detected->setReprojectionErrorMaxPx(m_cfgReprojectionErrorMaxPx);

   // 读取 AutoLiftControl 配置
   m_cfgSettleXyMm = iniReadThreshold->value("AutoLiftControl/SettleXyMm", 0.15).toDouble();
   m_cfgSettleYawDeg = iniReadThreshold->value("AutoLiftControl/SettleYawDeg", 0.15).toDouble();
   m_cfgStablePassCount = iniReadThreshold->value("AutoLiftControl/StablePassCount", 2).toInt();
   m_cfgMaxCorrections = iniReadThreshold->value("AutoLiftControl/MaxCorrectionCommandsPerHeight", 5).toInt();
   m_cfgCorrectionGain = iniReadThreshold->value("AutoLiftControl/CorrectionGain", 0.70).toDouble();
   m_cfgResidualGrowthStopRatio = iniReadThreshold->value("AutoLiftControl/ResidualGrowthStopRatio", 1.10).toDouble();
   m_cfgCrossHeightXyMm = iniReadThreshold->value("AutoLiftControl/CrossHeightXyMm", 1.5).toDouble();
   m_cfgCrossHeightYawDeg = iniReadThreshold->value("AutoLiftControl/CrossHeightYawDeg", 0.3).toDouble();

   // 读取 VisionSearch 配置
   m_cfgEnableSixDofSearch = iniReadThreshold->value("VisionSearch/EnableSixDofSearch", true).toBool();
   m_cfgSearchSafetyLeftMm = iniReadThreshold->value("VisionSearch/SearchSafetyLeftMm", 70).toDouble();
   m_cfgSearchSafetyRightMm = iniReadThreshold->value("VisionSearch/SearchSafetyRightMm", 70).toDouble();
   m_cfgSearchSafetyForwardMm = iniReadThreshold->value("VisionSearch/SearchSafetyForwardMm", 25).toDouble();
   m_cfgSearchSafetyBackwardMm = iniReadThreshold->value("VisionSearch/SearchSafetyBackwardMm", 70).toDouble();
   m_cfgSearchDistanceRatio = iniReadThreshold->value("VisionSearch/SearchDistanceRatio", 0.70).toDouble();
   m_cfgMaxDirectedSearchMoves = iniReadThreshold->value("VisionSearch/MaxDirectedSearchMoves", 2).toInt();
   m_cfgEnableBlindFallback = iniReadThreshold->value("VisionSearch/EnableBlindFallback", true).toBool();

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
    if (checkCollision_flag == false) {
        LiftUpdateUI("请先开启碰撞检测!");
        return false;
    }
    if (detected_flag == false) {
        LiftUpdateUI("请先进行视觉检测或平移找码检测!");
        return false;
    }
    if (autodescent || autolift) {
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

    float angle = m_angle;
    float distance_x = m_gapwidth_x;
    float distance_y = m_gapwidth_y;

    // 新模型下：mfr.x/y 即 alignError，目标值 = 0
    float xCorr = distance_x * m_cfgCorrectionGain;
    float yCorr = distance_y * m_cfgCorrectionGain;
    float yawCorr = angle * m_cfgCorrectionGain;

    if (qAbs(angle) > m_cfgSettleYawDeg) {
        m_SixDof->posePointMotion(x, y, z, rx, ry, rz - yawCorr, 2, 1);
        LiftUpdateUI("执行一次对齐：调整 yaw");
    } else if (qAbs(distance_x) > m_cfgSettleXyMm || qAbs(distance_y) > m_cfgSettleXyMm) {
        m_SixDof->posePointMotion(x + xCorr, y + yCorr, z, rx, ry, rz, 2, 1);
        LiftUpdateUI(QString("执行一次对齐：X=%1 Y=%2 yaw=%3")
                         .arg(distance_x, 0, 'f', 2)
                         .arg(distance_y, 0, 'f', 2)
                         .arg(angle, 0, 'f', 2));
    } else {
        LiftUpdateUI("执行一次对齐：误差已在阈值内");
    }
    detected_flag = false;
    return true;
}

bool Lift::getCurrentVisionDeviceIndex(int &deviceIndex, float &z)
{
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    if (z < -1.0f) {
        LiftUpdateUI("二级高度值获取错误");
        return false;
    }
    QJsonObject coordinates = m_SixDof->getCurrentCoordinates();
    float six_z = QString::number(coordinates["z"].toDouble(), 'f', 2).toFloat();

    if ((-0.5f <= z && z <= 0.5f) && (-1.0f <= six_z && six_z <= 1.0f))
        deviceIndex = 1;
    else if ((1699.5f <= z && z <= 1700.5f) && (-1.0f <= six_z && six_z <= 1.0f))
        deviceIndex = 0;
    else {
        deviceIndex = -1;
        LiftUpdateUI("不在视觉工作范围，请确认二级高度为0或1700mm且六自由度z≈0");
        return false;
    }
    return true;
}

bool Lift::vision_detected()
{
    if (autodescent || autolift) {
        LiftUpdateUI("自动运动中，请勿手动检测");
        return false;
    }
    detected_flag = false;

    if (!m_zm->GetConnectStatus()) {
        LiftUpdateUI("未连接控制器");
        return false;
    }
    if (!m_dahengCamera) {
        LiftUpdateUI("相机对象失效");
        return false;
    }

    emit sendBrightnessValueToMainWindow(255);
    QThread::sleep(1);

    int deviceIndex = -1;
    float z = 0.0f;
    if (!getCurrentVisionDeviceIndex(deviceIndex, z))
        return false;

    LiftUpdateUI("视觉检测：开始");
    MultiFrameResult mfr = detectMultiFrame(deviceIndex);
    if (!mfr.valid) {
        LiftUpdateUI("视觉检测失败：未找到目标码，可尝试平移找码检测");
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
    LiftUpdateUI(QString("视觉检测：成功 X=%1 Y=%2 yaw=%3 有效帧%4/%5")
                     .arg(m_gapwidth_x, 0, 'f', 2)
                     .arg(m_gapwidth_y, 0, 'f', 2)
                     .arg(m_angle, 0, 'f', 2)
                     .arg(mfr.validFrameCount).arg(mfr.sampledFrameCount));
    return true;
}

bool Lift::search_vision_detected()
{
    if (autodescent || autolift) {
        LiftUpdateUI("自动运动中，请勿手动检测");
        return false;
    }
    detected_flag = false;

    if (!m_zm->GetConnectStatus()) {
        LiftUpdateUI("未连接控制器");
        return false;
    }
    if (!m_dahengCamera) {
        LiftUpdateUI("相机对象失效");
        return false;
    }

    emit sendBrightnessValueToMainWindow(255);
    QThread::sleep(1);

    int deviceIndex = -1;
    float z = 0.0f;
    if (!getCurrentVisionDeviceIndex(deviceIndex, z))
        return false;

    LiftUpdateUI("平移找码：开始");
    MultiFrameResult mfr = detectMultiFrameWithSixDofSearch(deviceIndex, SearchSuccessMode::ReturnToStart);
    if (!mfr.valid) {
        LiftUpdateUI("平移找码失败：请检查遮挡/光源/marker_id");
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
    LiftUpdateUI("平移找码：找到码，已回到找码前位置");
    return true;
}

bool Lift::auto_align()
{
    if (autodescent || autolift) {
        LiftUpdateUI("自动运动中，请勿手动操作");
        return false;
    }
    if (!m_zm->GetConnectStatus()) {
        LiftUpdateUI("未连接控制器");
        return false;
    }
    if (checkCollision_flag == false) {
        LiftUpdateUI("请先开启碰撞检测!");
        return false;
    }

    int deviceIndex = -1;
    float z = 0.0f;
    if (!getCurrentVisionDeviceIndex(deviceIndex, z))
        return false;

    // 使用局部 autolift 标志驱动 runAutoLiftVisionStage，但不影响外部自动流程
    bool previousAutoLift = autolift;
    autolift = true;
    StageResidual residual;
    bool ok = runAutoLiftVisionStage(deviceIndex, "自动对齐", residual);
    autolift = previousAutoLift;

    if (ok) {
        LiftUpdateUI("自动对齐：完成");
    } else {
        LiftUpdateUI("自动对齐：失败，已停止");
    }
    return ok;
}


// =============================================================================
//    单高度闭环 stage：检测 → 补偿 → 复测 → 稳定确认
// =============================================================================
bool Lift::runAutoLiftVisionStage(int deviceIndex, const QString& label,
                                   StageResidual& outResidual)
{
    int corrections = 0;
    int stableCount = 0;

    while (corrections < m_cfgMaxCorrections && autolift) {
        LiftUpdateUI(label + ": 多帧检测");
        MultiFrameResult mfr = detectMultiFrameWithSixDofSearch(deviceIndex, SearchSuccessMode::StayAtFoundPosition);
        if (!mfr.valid) {
            AutoLiftDiagnostics diag;
            diag.mfr = mfr;
            diag.stageLabel = label;
            diag.stopReason = mfr.failureReason;
            softStop(diag);
            return false;
        }

        // 新模型下：mfr.x/y 就是 alignError，目标值 = 0
        float xRes = mfr.x;
        float yRes = mfr.y;
        float yawRes = mfr.yaw;

        if (qAbs(xRes) <= m_cfgSettleXyMm && qAbs(yRes) <= m_cfgSettleXyMm && qAbs(yawRes) <= m_cfgSettleYawDeg) {
            stableCount++;
            LiftUpdateUI(QString("%1: 稳定%2/%3").arg(label).arg(stableCount).arg(m_cfgStablePassCount));
            if (stableCount >= m_cfgStablePassCount) {
                outResidual.x = xRes; outResidual.y = yRes; outResidual.yaw = yawRes;
                LiftUpdateUI(label + ": 已稳定");
                return true;
            }
            QThread::msleep(200);
            continue;
        }
        stableCount = 0;

        double oldScore = residualScore(xRes, yRes, yawRes);
        double yawCorr = 0, xCorr = 0, yCorr = 0;

        QJsonObject coords = m_SixDof->getCurrentCoordinates();
        float cx  = QString::number(coords["x"].toDouble(),  'f', 2).toFloat();
        float cy  = QString::number(coords["y"].toDouble(),  'f', 2).toFloat();
        float cz  = QString::number(coords["z"].toDouble(),  'f', 2).toFloat();
        float crx = QString::number(coords["rx"].toDouble(), 'f', 2).toFloat();
        float cry = QString::number(coords["ry"].toDouble(), 'f', 2).toFloat();
        float crz = QString::number(coords["rz"].toDouble(), 'f', 2).toFloat();

        // 先 yaw、再 xy
        if (qAbs(yawRes) > m_cfgSettleYawDeg) {
            yawCorr = yawRes * m_cfgCorrectionGain;
            m_SixDof->posePointMotion(cx, cy, cz, crx, cry, crz - yawCorr, 2, 1);
        } else {
            xCorr = mfr.x * m_cfgCorrectionGain;
            yCorr = mfr.y * m_cfgCorrectionGain;
            m_SixDof->posePointMotion(cx + xCorr, cy + yCorr, cz, crx, cry, crz, 2, 1);
        }
        waitSixDof();
        corrections++;

        // 补偿后复测
        MultiFrameResult postMfr = detectMultiFrameWithSixDofSearch(deviceIndex, SearchSuccessMode::StayAtFoundPosition);
        if (!postMfr.valid) {
            AutoLiftDiagnostics diag;
            diag.mfr = postMfr;
            diag.stageLabel = label;
            diag.correctionCount = corrections;
            diag.maxCorrections = m_cfgMaxCorrections;
            diag.xRes = xRes; diag.yRes = yRes; diag.yawRes = yawRes;
            diag.xCorrection = xCorr; diag.yCorrection = yCorr; diag.yawCorrection = yawCorr;
            diag.stopReason = "补偿后复测失败";
            softStop(diag);
            return false;
        }
        double postScore = residualScore(postMfr.x, postMfr.y, postMfr.yaw);
        if (postScore > oldScore * m_cfgResidualGrowthStopRatio) {
            AutoLiftDiagnostics diag;
            diag.mfr = postMfr;
            diag.stageLabel = label;
            diag.correctionCount = corrections;
            diag.maxCorrections = m_cfgMaxCorrections;
            diag.xRes = postMfr.x; diag.yRes = postMfr.y; diag.yawRes = postMfr.yaw;
            diag.xCorrection = xCorr; diag.yCorrection = yCorr; diag.yawCorrection = yawCorr;
            diag.residualGrew = true;
            diag.stopReason = QString("补偿后残差增大: score %1→%2").arg(oldScore, 0, 'f', 2).arg(postScore, 0, 'f', 2);
            softStop(diag);
            return false;
        }

        // 复测结果参与稳定判断
        float postXRes = postMfr.x;
        float postYRes = postMfr.y;
        float postYawRes = postMfr.yaw;
        if (qAbs(postXRes) <= m_cfgSettleXyMm && qAbs(postYRes) <= m_cfgSettleXyMm && qAbs(postYawRes) <= m_cfgSettleYawDeg) {
            stableCount++;
            LiftUpdateUI(QString("%1: 补偿后稳定%2/%3").arg(label).arg(stableCount).arg(m_cfgStablePassCount));
            if (stableCount >= m_cfgStablePassCount) {
                outResidual.x = postXRes; outResidual.y = postYRes; outResidual.yaw = postYawRes;
                LiftUpdateUI(label + ": 补偿后已稳定");
                return true;
            }
        } else {
            stableCount = 0;
        }
    }

    AutoLiftDiagnostics diag;
    diag.stageLabel = label;
    diag.correctionCount = corrections;
    diag.maxCorrections = m_cfgMaxCorrections;
    diag.stopReason = QString("%1 未能稳定，已补偿%2次").arg(label).arg(corrections);
    softStop(diag);
    return false;
}

bool Lift::runAutoDescentVisionStage(int deviceIndex, const QString& label,
                                      StageResidual& outResidual)
{
    int corrections = 0;
    int stableCount = 0;

    while (corrections < m_cfgMaxCorrections && autodescent) {
        LiftUpdateUI(label + ": 多帧检测");
        MultiFrameResult mfr = detectMultiFrameWithSixDofSearch(deviceIndex, SearchSuccessMode::StayAtFoundPosition);
        if (!mfr.valid) {
            AutoLiftDiagnostics diag;
            diag.mfr = mfr;
            diag.stageLabel = label;
            diag.correctionCount = corrections;
            diag.maxCorrections = m_cfgMaxCorrections;
            diag.stopReason = mfr.failureReason;
            softStop(diag);
            autodescent = false;
            return false;
        }

        float xRes = mfr.x;
        float yRes = mfr.y;
        float yawRes = mfr.yaw;
        qInfo() << QString("%1: 下降闭环检测 x=%2 y=%3 yaw=%4")
                       .arg(label).arg(xRes, 0, 'f', 3).arg(yRes, 0, 'f', 3).arg(yawRes, 0, 'f', 3);

        if (qAbs(xRes) <= m_cfgSettleXyMm && qAbs(yRes) <= m_cfgSettleXyMm && qAbs(yawRes) <= m_cfgSettleYawDeg) {
            stableCount++;
            LiftUpdateUI(QString("%1: 稳定%2/%3").arg(label).arg(stableCount).arg(m_cfgStablePassCount));
            if (stableCount >= m_cfgStablePassCount) {
                outResidual.x = xRes; outResidual.y = yRes; outResidual.yaw = yawRes;
                detected_flag = false;
                LiftUpdateUI(label + ": 已稳定");
                return true;
            }
            QThread::msleep(200);
            continue;
        }
        stableCount = 0;

        double oldScore = residualScore(xRes, yRes, yawRes);
        m_angle = mfr.yaw;
        m_gapwidth_x = mfr.x;
        m_gapwidth_y = mfr.y;
        detected_flag = true;

        if (!autodescent) { LiftUpdateUI("自动下降已终止"); return false; }
        if (!descent_StatusModifyLatte()) {
            AutoLiftDiagnostics diag;
            diag.mfr = mfr;
            diag.stageLabel = label;
            diag.correctionCount = corrections;
            diag.maxCorrections = m_cfgMaxCorrections;
            diag.xRes = xRes; diag.yRes = yRes; diag.yawRes = yawRes;
            diag.stopReason = "平台运动失败，自动下降已终止";
            softStop(diag);
            autodescent = false;
            return false;
        }
        waitSixDof();
        corrections++;
        qInfo() << QString("%1: 第%2次平台调整完成").arg(label).arg(corrections);

        if (!autodescent) { LiftUpdateUI("自动下降已终止"); return false; }
        MultiFrameResult postMfr = detectMultiFrameWithSixDofSearch(deviceIndex, SearchSuccessMode::StayAtFoundPosition);
        if (!postMfr.valid) {
            AutoLiftDiagnostics diag;
            diag.mfr = postMfr;
            diag.stageLabel = label;
            diag.correctionCount = corrections;
            diag.maxCorrections = m_cfgMaxCorrections;
            diag.xRes = xRes; diag.yRes = yRes; diag.yawRes = yawRes;
            diag.stopReason = "补偿后复测失败";
            softStop(diag);
            autodescent = false;
            return false;
        }

        double postScore = residualScore(postMfr.x, postMfr.y, postMfr.yaw);
        qInfo() << QString("%1: 补偿后残差 score %2 -> %3, x=%4 y=%5 yaw=%6")
                       .arg(label).arg(oldScore, 0, 'f', 3).arg(postScore, 0, 'f', 3)
                       .arg(postMfr.x, 0, 'f', 3).arg(postMfr.y, 0, 'f', 3).arg(postMfr.yaw, 0, 'f', 3);

        if (postScore > oldScore * m_cfgResidualGrowthStopRatio) {
            AutoLiftDiagnostics diag;
            diag.mfr = postMfr;
            diag.stageLabel = label;
            diag.correctionCount = corrections;
            diag.maxCorrections = m_cfgMaxCorrections;
            diag.xRes = postMfr.x; diag.yRes = postMfr.y; diag.yawRes = postMfr.yaw;
            diag.residualGrew = true;
            diag.stopReason = QString("补偿后残差增大: score %1→%2").arg(oldScore, 0, 'f', 2).arg(postScore, 0, 'f', 2);
            softStop(diag);
            autodescent = false;
            return false;
        }

        if (qAbs(postMfr.x) <= m_cfgSettleXyMm && qAbs(postMfr.y) <= m_cfgSettleXyMm && qAbs(postMfr.yaw) <= m_cfgSettleYawDeg) {
            stableCount++;
            LiftUpdateUI(QString("%1: 补偿后稳定%2/%3").arg(label).arg(stableCount).arg(m_cfgStablePassCount));
            if (stableCount >= m_cfgStablePassCount) {
                outResidual.x = postMfr.x; outResidual.y = postMfr.y; outResidual.yaw = postMfr.yaw;
                detected_flag = false;
                LiftUpdateUI(label + ": 补偿后已稳定");
                return true;
            }
        } else {
            stableCount = 0;
        }
    }

    if (!autodescent) {
        LiftUpdateUI("自动下降已终止");
        return false;
    }

    AutoLiftDiagnostics diag;
    diag.stageLabel = label;
    diag.correctionCount = corrections;
    diag.maxCorrections = m_cfgMaxCorrections;
    diag.stopReason = QString("%1 未能稳定，已补偿%2次").arg(label).arg(corrections);
    softStop(diag);
    autodescent = false;
    return false;
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

    m_autoLiftCompleted = false;
    float goal_z = final_z_lift;
    float z = 0.0;
    bool hasZ0Residual = false;

    // ================================================================
    //  阶段1：z≈0，相机1
    // ================================================================
    StageResidual z0Residual;
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    if (z >= -0.5f && z < 0.5f && autolift) {
        if (!runAutoLiftVisionStage(1, "z≈0", z0Residual)) return false;
        hasZ0Residual = true;
    }

    // ================================================================
    //  升到 z≈1700
    // ================================================================
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    if (z < 1700) {
        LiftUpdateUI("二级抬升至1700mm");
        m_zm->MoveSingleAbs(12, 1700);
        QThread::msleep(200);
        while (!m_zm->IsSingleIdle(12)) {
            if (!autolift) { LiftUpdateUI("自动抬升已终止"); return false; }
            QThread::msleep(100);
        }
    }

    // ================================================================
    //  阶段2：z≈1700，相机0
    // ================================================================
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    StageResidual z1700Residual;
    if (z > 1699.5f && z < 1700.5f && autolift) {
        if (!runAutoLiftVisionStage(0, "z≈1700", z1700Residual)) return false;

        // 跨高度一致性检查
        if (!hasZ0Residual) {
            AutoLiftDiagnostics diag;
            diag.stageLabel = "跨高度一致性";
            diag.stopReason = "缺少 z≈0 检测结果，无法做跨高度一致性检查";
            softStop(diag);
            return false;
        }
        if (qAbs(z1700Residual.x - z0Residual.x) > m_cfgCrossHeightXyMm ||
            qAbs(z1700Residual.y - z0Residual.y) > m_cfgCrossHeightXyMm ||
            qAbs(z1700Residual.yaw - z0Residual.yaw) > m_cfgCrossHeightYawDeg) {
            AutoLiftDiagnostics diag;
            diag.stageLabel = "跨高度一致性";
            diag.xRes = z1700Residual.x - z0Residual.x;
            diag.yRes = z1700Residual.y - z0Residual.y;
            diag.yawRes = z1700Residual.yaw - z0Residual.yaw;
            diag.stopReason = QString("跨高度残差不一致: z0(x=%1,y=%2,yaw=%3) z1700(x=%4,y=%5,yaw=%6)")
                                  .arg(z0Residual.x,0,'f',3).arg(z0Residual.y,0,'f',3).arg(z0Residual.yaw,0,'f',3)
                                  .arg(z1700Residual.x,0,'f',3).arg(z1700Residual.y,0,'f',3).arg(z1700Residual.yaw,0,'f',3);
            softStop(diag);
            return false;
        }
        LiftUpdateUI("跨高度残差一致");
    }

    // ================================================================
    //  升到 final_z_lift
    // ================================================================
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
    if (1700 <= z) {
        LiftUpdateUI("二级抬升到最终高度");
        m_zm->MoveSingleAbs(12, goal_z);
        QThread::msleep(200);
        while (!m_zm->IsSingleIdle(12)) {
            if (!autolift) { LiftUpdateUI("自动抬升已终止"); return false; }
            QThread::msleep(100);
        }
    }

    QThread::msleep(500);
    QJsonObject coordinates = m_SixDof->getCurrentCoordinates();
    float six_x = QString::number(coordinates["x"].toDouble(), 'f', 2).toFloat();
    float six_y = QString::number(coordinates["y"].toDouble(), 'f', 2).toFloat();
    emit sigAutoLiftFinalSixDofCoordinates(six_x, six_y);
    autolift = false;
    m_autoLiftCompleted = true;
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

    float z = m_zm->myZmotionStatus->allAxisStatus[12].posi;

    // 路径A：auto_lift 刚完成 → 纯轨迹反转
    if (m_autoLiftCompleted) {
        if (z > 1700.5f && autodescent) {
            LiftUpdateUI("二级下降至1700");
            m_zm->MoveSingleAbs(12, 1700);
            QThread::msleep(200);
            while (!m_zm->IsSingleIdle(12)) {
                if (!autodescent) { LiftUpdateUI("自动下降已终止"); return false; }
                QThread::msleep(100);
            }
        }
        QThread::msleep(500);
        z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
        if (z > 0 && autodescent) {
            LiftUpdateUI("二级下降至0");
            m_zm->MoveSingleAbs(12, 0);
            QThread::msleep(200);
            while (!m_zm->IsSingleIdle(12)) {
                if (!autodescent) { LiftUpdateUI("自动下降已终止"); return false; }
                QThread::msleep(100);
            }
        }
        m_autoLiftCompleted = false;
        autodescent = false;
        LiftUpdateUI("自动下降运动完成");
        return true;
    }

    // 路径B：无抬升 → 降到1700后做闭环视觉调整，再降到0
    if (z > 1700 && autodescent) {
        LiftUpdateUI("二级下降中");
        m_zm->MoveSingleAbs(12, 1700);
        QThread::msleep(200);
        while (!m_zm->IsSingleIdle(12)) {
            if (!autodescent) { LiftUpdateUI("自动下降已终止"); return false; }
            QThread::msleep(100);
        }
    }
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;

    if (z > 1699.5f && z < 1700.5f && autodescent) {
        StageResidual descentResidual;
        if (!runAutoDescentVisionStage(0, "自动下降1700mm", descentResidual)) {
            return false;
        }
    }
    QThread::msleep(500);
    z = m_zm->myZmotionStatus->allAxisStatus[12].posi;

    if (z <= 1700 && autodescent) {
        LiftUpdateUI("二级下降中");
        m_zm->MoveSingleAbs(12, 0);
        QThread::msleep(200);
        while (!m_zm->IsSingleIdle(12)) {
            if (!autodescent) { LiftUpdateUI("自动下降已终止"); return false; }
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
    m_autoLiftCompleted = false;
    m_zm->EmergencyStop();
    m_SixDof->stopMotion();
    m_zm->EmergencyStop();
}

void Lift::waitSixDof()
{
    QThread::msleep(300);
    bool logged = false;
    while (m_SixDof->isPlatformMoving() && (autolift || autodescent)) {
        if (!logged) {
            LiftUpdateUI("等待六自由度就位");
            logged = true;
        }
        QThread::msleep(100);
    }
}

bool Lift::waitSixDofForSearch(int timeoutMs)
{
    QThread::msleep(300);
    QElapsedTimer t;
    t.start();
    bool logged = false;
    while (m_SixDof->isPlatformMoving() && t.elapsed() < timeoutMs) {
        if (!logged) {
            LiftUpdateUI("等待六自由度就位(找码)");
            logged = true;
        }
        QThread::msleep(100);
    }
    if (m_SixDof->isPlatformMoving()) {
        LiftUpdateUI("六自由度找码等待超时，停止平台运动");
        m_SixDof->stopMotion();
        return false;
    }
    return true;
}

void Lift::convertSearchResultToOrigin(MultiFrameResult &result,
                                       double platformDx,
                                       double platformDy,
                                       const QString &sourceLabel)
{
    const double rawX = result.x;
    const double rawY = result.y;

    // 新模型下平台 +X=车头/前，+Y=车左/左。
    // 平台从原点移动到 (platformDx, platformDy) 后测得的残差，
    // 换算回原点基准时应加上同样的平台位移。
    result.x = rawX + platformDx;
    result.y = rawY + platformDy;

    QString msg = QString("六自由度找码换算 @%1: move dx=%2 dy=%3 raw x=%4 y=%5 origin x=%6 y=%7")
                      .arg(sourceLabel)
                      .arg(platformDx, 0, 'f', 2)
                      .arg(platformDy, 0, 'f', 2)
                      .arg(rawX, 0, 'f', 2)
                      .arg(rawY, 0, 'f', 2)
                      .arg(result.x, 0, 'f', 2)
                      .arg(result.y, 0, 'f', 2);
    qInfo() << msg;
}

// =============================================================================
//    多帧检测 helper
// =============================================================================
// =============================================================================
//    等待一帧新帧
// =============================================================================
std::pair<cv::Mat, int64_t> Lift::waitNextFrame(int deviceIndex, int64_t afterSeq, int timeoutMs)
{
    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < timeoutMs) {
        auto [mat, seq] = m_dahengCamera->getlatestframeWithSeq(deviceIndex);
        if (!mat.empty() && seq != afterSeq && seq >= 0) {
            return {mat, seq};
        }
        QThread::msleep(5);
    }
    return {cv::Mat(), afterSeq};  // 超时
}

// =============================================================================
//    多帧采样检测
// =============================================================================
Lift::MultiFrameResult Lift::detectMultiFrame(int deviceIndex)
{
    MultiFrameResult mfr;

    int exposureUs = m_dahengCamera->getExposureTimeUs(deviceIndex);
    int timeoutMs = qMax(1000, 2 * (exposureUs / 1000) + 200);

    int consecutiveRetries = 0;
    const int maxRetries = m_cfgBatchRetryCount;

    // 取 baseline seq，等待 seq >= 0
    auto [baseline, baselineSeq] = m_dahengCamera->getlatestframeWithSeq(deviceIndex);
    int64_t lastSeq = baselineSeq;

    // 搜索线索聚合（用于失败时提供找码方向）
    double sumOffsetPxX = 0, sumOffsetPxY = 0;
    int    hintFrameCount = 0;
    double sumTvecX = 0, sumTvecY = 0;
    int    pnpHintCount = 0;
    QMap<QString, int> failureCounts;

    while (consecutiveRetries <= maxRetries) {
        struct FrameSample { double x; double y; double yaw; };
        QVector<FrameSample> samples;
        int sampledFrames = 0;
        int rawValidFrames = 0;

        for (int i = 0; i < m_cfgFrameCount; ++i) {
            auto [mat, seq] = waitNextFrame(deviceIndex, lastSeq, timeoutMs);
            if (mat.empty()) continue;  // 超时
            lastSeq = seq;
            sampledFrames++;

            float z = m_zm->myZmotionStatus->allAxisStatus[12].posi;
            ArucoDetector::DetailedFrameResult frameResult =
                m_vision_detected->processImageDetailed(mat, z);

            // ★ 收集搜索线索（无论帧是否有效）
            if (frameResult.hasSearchHint) {
                if (frameResult.targetSeen) {
                    sumOffsetPxX += frameResult.markerOffsetPxX;
                    sumOffsetPxY += frameResult.markerOffsetPxY;
                    hintFrameCount++;
                }
                if (frameResult.hasPnpHint) {
                    sumTvecX += frameResult.hintTvecX;
                    sumTvecY += frameResult.hintTvecY;
                    pnpHintCount++;
                }
            }
            if (!frameResult.valid && !frameResult.failureReason.isEmpty()) {
                failureCounts[frameResult.failureReason]++;
            }

            if (!frameResult.valid) continue;

            rawValidFrames++;
            samples.push_back({frameResult.x, frameResult.y, frameResult.yaw});
        }

        if (rawValidFrames < m_cfgMinValidFrames) {
            mfr.sampledFrameCount = sampledFrames;
            mfr.rawValidFrameCount = rawValidFrames;
            mfr.failureReason = QString("单帧有效帧不足: %1/%2 (采样%3帧)")
                                    .arg(rawValidFrames).arg(m_cfgMinValidFrames).arg(sampledFrames);
            LiftUpdateUI(mfr.failureReason);
            consecutiveRetries++;
            continue;
        }

        // 提取 x/y/yaw 到临时副本，在副本上排序求中位数，不改变 samples 顺序
        auto medianOnCopy = [](const QVector<FrameSample>& src,
                               double FrameSample::*field) -> double {
            if (src.isEmpty()) return 0.0;
            QVector<double> copy;
            copy.reserve(src.size());
            for (const auto& s : src) copy.push_back(s.*field);
            std::sort(copy.begin(), copy.end());
            return copy[copy.size() / 2];
        };
        double medX = medianOnCopy(samples, &FrameSample::x);
        double medY = medianOnCopy(samples, &FrameSample::y);
        double medYaw = medianOnCopy(samples, &FrameSample::yaw);

        // 遍历原始 samples 做跳变过滤
        QVector<FrameSample> filtered;
        for (const auto& s : samples) {
            if (std::abs(s.x - medX) <= m_cfgJumpXyMm &&
                std::abs(s.y - medY) <= m_cfgJumpXyMm &&
                std::abs(s.yaw - medYaw) <= m_cfgJumpYawDeg) {
                filtered.push_back(s);
            }
        }

        int filteredCount = filtered.size();
        if (filteredCount < m_cfgMinValidFrames) {
            mfr.sampledFrameCount = sampledFrames;
            mfr.rawValidFrameCount = rawValidFrames;
            mfr.validFrameCount = filteredCount;
            mfr.failureReason = QString("剔除跳变后有效帧不足: %1/%2 (采样%3, 单帧有效%4)")
                                    .arg(filteredCount).arg(m_cfgMinValidFrames)
                                    .arg(sampledFrames).arg(rawValidFrames);
            LiftUpdateUI(mfr.failureReason);
            consecutiveRetries++;
            continue;
        }

        // 过滤后的结果取中位数输出，也用副本排序
        mfr.x = medianOnCopy(filtered, &FrameSample::x);
        mfr.y = medianOnCopy(filtered, &FrameSample::y);
        mfr.yaw = medianOnCopy(filtered, &FrameSample::yaw);
        mfr.sampledFrameCount = sampledFrames;
        mfr.rawValidFrameCount = rawValidFrames;
        mfr.validFrameCount = filteredCount;
        mfr.valid = true;

        LiftUpdateUI(QString("自动对齐：复测 X=%1 Y=%2 yaw=%3")
                         .arg(mfr.x, 0, 'f', 3).arg(mfr.y, 0, 'f', 3).arg(mfr.yaw, 0, 'f', 3));
        qInfo() << QString("多帧检测成功: 采样%1, 有效%2, 过滤后%3/%4, x=%5 y=%6 yaw=%7")
                         .arg(sampledFrames).arg(rawValidFrames).arg(filteredCount).arg(m_cfgFrameCount)
                         .arg(mfr.x, 0, 'f', 3).arg(mfr.y, 0, 'f', 3).arg(mfr.yaw, 0, 'f', 3);
        return mfr;
    }

    // ★ 失败时填充搜索线索，供 detectMultiFrameWithSixDofSearch 使用
    if (hintFrameCount > 0) {
        mfr.hasSearchHint = true;
        mfr.markerOffsetPxX = sumOffsetPxX / hintFrameCount;
        mfr.markerOffsetPxY = sumOffsetPxY / hintFrameCount;
    }
    if (pnpHintCount > 0) {
        mfr.hasPnpHint = true;
        mfr.hintTvecX = sumTvecX / pnpHintCount;
        mfr.hintTvecY = sumTvecY / pnpHintCount;
        mfr.hasSearchHint = true;
    }
    // 找出最主要的失败原因
    if (!failureCounts.isEmpty()) {
        auto it = std::max_element(failureCounts.begin(), failureCounts.end(),
                                   [](const auto& a, const auto& b) { return a < b; });
        mfr.dominantFailureReason = it.key();
    }

    if (mfr.failureReason.isEmpty()) {
        mfr.failureReason = QString("多帧检测失败，重试%1次后仍然无效").arg(maxRetries);
    }
    qInfo() << mfr.failureReason;
    return mfr;
}

// =============================================================================
//    多帧检测 + 六自由度平移找码
//    原点检测失败时不立刻报失败，利用六自由度平台平移找码
// =============================================================================
Lift::MultiFrameResult Lift::detectMultiFrameWithSixDofSearch(int deviceIndex,
                                                               SearchSuccessMode mode)
{
    // 1. 记录六自由度原始位置
    QJsonObject originCoords = m_SixDof->getCurrentCoordinates();
    double origin_x = originCoords["x"].toDouble();
    double origin_y = originCoords["y"].toDouble();
    double origin_z = originCoords["z"].toDouble();
    double origin_rx = originCoords["rx"].toDouble();
    double origin_ry = originCoords["ry"].toDouble();
    double origin_rz = originCoords["rz"].toDouble();

    auto returnToOrigin = [&]() -> bool {
        m_SixDof->posePointMotion(origin_x, origin_y, origin_z, origin_rx, origin_ry, origin_rz, 2, 1);
        return waitSixDofForSearch(15000);
    };

    // 2. 原点检测
    MultiFrameResult mfr = detectMultiFrame(deviceIndex);
    if (mfr.valid) {
        return mfr;
    }

    // 3. 检查是否启用找码
    if (!m_cfgEnableSixDofSearch) {
        LiftUpdateUI("六自由度找码已禁用，返回原点检测结果");
        return mfr;
    }

    // 4. 准备移动距离
    double moveDistLeft    = m_cfgSearchSafetyLeftMm    * m_cfgSearchDistanceRatio;
    double moveDistRight   = m_cfgSearchSafetyRightMm   * m_cfgSearchDistanceRatio;
    double moveDistForward = m_cfgSearchSafetyForwardMm * m_cfgSearchDistanceRatio;
    double moveDistBack    = m_cfgSearchSafetyBackwardMm * m_cfgSearchDistanceRatio;

    int totalMoves = 0;
    const int maxMoves = m_cfgMaxDirectedSearchMoves > 0 ? m_cfgMaxDirectedSearchMoves : 2;

    MultiFrameResult currentMfr = mfr;

    // ================================================================
    // 阶段 A：定向找码（最多 maxMoves 次，每次用最新结果重判方向）
    // ================================================================
    while (totalMoves < maxMoves) {
        struct { QString label; double dx; double dy; bool valid = false; } bestMove;

        // A1. PnP 优先：相机系线索先转平台系。平台 +X=车头/前，+Y=车左/左。
        if (currentMfr.hasPnpHint) {
            double camX = currentMfr.hintTvecX;
            double camY = currentMfr.hintTvecY;
            double platformHintX = -camY;
            double platformHintY =  camX;
            if (std::abs(platformHintX) >= std::abs(platformHintY)) {
                if (platformHintX > 5.0)       bestMove = {"PnP→前", moveDistForward, 0, true};
                else if (platformHintX < -5.0) bestMove = {"PnP→后", -moveDistBack, 0, true};
            } else {
                if (platformHintY > 5.0)       bestMove = {"PnP→左", 0, moveDistLeft, true};
                else if (platformHintY < -5.0) bestMove = {"PnP→右", 0, -moveDistRight, true};
            }
        }

        // A2. 像素偏移：无 PnP 时按同一平台系方向近似判断，选偏移更大的轴
        if (!bestMove.valid && currentMfr.hasSearchHint) {
            double px = currentMfr.markerOffsetPxX;
            double py = currentMfr.markerOffsetPxY;
            double platformHintX = -py;
            double platformHintY =  px;
            if (std::abs(platformHintX) >= std::abs(platformHintY)) {
                if (platformHintX > 100)       bestMove = {"像素→前", moveDistForward, 0, true};
                else if (platformHintX < -100) bestMove = {"像素→后", -moveDistBack, 0, true};
            } else {
                if (platformHintY > 100)       bestMove = {"像素→左", 0, moveDistLeft, true};
                else if (platformHintY < -100) bestMove = {"像素→右", 0, -moveDistRight, true};
            }
        }

        if (!bestMove.valid) break;  // 无法确定方向，跳出定向阶段

        // A3. 计算目标位置
        double target_x = origin_x + bestMove.dx;
        double target_y = origin_y + bestMove.dy;

        // 安全检查：总偏移不得超过安全范围
        double dx = target_x - origin_x;
        double dy = target_y - origin_y;
        dx = qBound(-m_cfgSearchSafetyBackwardMm, dx, m_cfgSearchSafetyForwardMm);
        dy = qBound(-m_cfgSearchSafetyRightMm,    dy, m_cfgSearchSafetyLeftMm);
        target_x = origin_x + dx;
        target_y = origin_y + dy;

        LiftUpdateUI(QString("六自由度找码 %1 (第%2次): 移动到 (%3, %4)")
                         .arg(bestMove.label).arg(totalMoves + 1)
                         .arg(target_x, 0, 'f', 1).arg(target_y, 0, 'f', 1));
        qInfo() << QString("六自由度找码移动 %1: (%2, %3)")
                         .arg(bestMove.label).arg(target_x, 0, 'f', 1).arg(target_y, 0, 'f', 1);

        m_SixDof->posePointMotion(target_x, target_y, origin_z, origin_rx, origin_ry, origin_rz, 2, 1);
        if (!waitSixDofForSearch(15000)) {
            QString reason = QString("六自由度找码移动超时: %1").arg(bestMove.label);
            LiftUpdateUI(reason + "，停止找码并尝试回原点");
            if (!returnToOrigin()) {
                reason += "，且回原点超时";
                emit UpdateSystemInfo(reason);
            }
            mfr.failureReason = QString("%1 | %2").arg(reason).arg(mfr.failureReason);
            return mfr;
        }

        MultiFrameResult retryMfr = detectMultiFrame(deviceIndex);
        totalMoves++;

        if (retryMfr.valid) {
            if (mode == SearchSuccessMode::ReturnToStart) {
                // 成功！换算回原点
                double dx_final = target_x - origin_x;
                double dy_final = target_y - origin_y;
                convertSearchResultToOrigin(retryMfr, dx_final, dy_final, bestMove.label);

                LiftUpdateUI(QString("六自由度找码成功 @%1: 换算回原点 (%2, %3)")
                                 .arg(bestMove.label)
                                 .arg(retryMfr.x, 0, 'f', 2)
                                 .arg(retryMfr.y, 0, 'f', 2));
                qInfo() << QString("六自由度找码成功 @%1: 换算回原点 (%2, %3)")
                                 .arg(bestMove.label)
                                 .arg(retryMfr.x, 0, 'f', 2)
                                 .arg(retryMfr.y, 0, 'f', 2);

                // 回原点
                if (!returnToOrigin()) {
                    retryMfr.valid = false;
                    retryMfr.failureReason = "六自由度找码成功但回原点超时，请人工确认平台位置";
                    emit UpdateSystemInfo(retryMfr.failureReason);
                }
            } else {
                LiftUpdateUI(QString("六自由度找码成功 @%1: 停在找到码位置继续闭环")
                                 .arg(bestMove.label));
                qInfo() << QString("六自由度找码成功 @%1: 停在找到码位置继续闭环")
                                 .arg(bestMove.label);
            }
            return retryMfr;
        }

        // 失败：用最新结果更新线索，下一轮重新判断方向
        currentMfr = retryMfr;
    }

    // ================================================================
    // 阶段 B：四方向盲扫兜底（如果启用）
    // ================================================================
    if (m_cfgEnableBlindFallback) {
        if (!currentMfr.hasSearchHint) {
            qInfo() << "原点未看到目标 marker，启用四方向盲扫";
        } else {
            qInfo() << "定向找码失败，启用四方向盲扫兜底";
        }

        struct { QString label; double dx; double dy; } blindMoves[] = {
            {"盲扫↑前",  moveDistForward, 0},
            {"盲扫↓后", -moveDistBack, 0},
            {"盲扫←左", 0,  moveDistLeft},
            {"盲扫→右", 0, -moveDistRight},
        };

        for (const auto &move : blindMoves) {
            double target_x = origin_x + move.dx;
            double target_y = origin_y + move.dy;

            double dx = target_x - origin_x;
            double dy = target_y - origin_y;
            dx = qBound(-m_cfgSearchSafetyBackwardMm, dx, m_cfgSearchSafetyForwardMm);
            dy = qBound(-m_cfgSearchSafetyRightMm,    dy, m_cfgSearchSafetyLeftMm);
            target_x = origin_x + dx;
            target_y = origin_y + dy;

            LiftUpdateUI(QString("六自由度找码 %1: 移动到 (%2, %3)")
                             .arg(move.label).arg(target_x, 0, 'f', 1).arg(target_y, 0, 'f', 1));
            qInfo() << QString("六自由度找码移动 %1: (%2, %3)")
                             .arg(move.label).arg(target_x, 0, 'f', 1).arg(target_y, 0, 'f', 1);

            m_SixDof->posePointMotion(target_x, target_y, origin_z, origin_rx, origin_ry, origin_rz, 2, 1);
            if (!waitSixDofForSearch(15000)) {
                QString reason = QString("六自由度找码移动超时: %1").arg(move.label);
                LiftUpdateUI(reason + "，停止找码并尝试回原点");
                if (!returnToOrigin()) {
                    reason += "，且回原点超时";
                    emit UpdateSystemInfo(reason);
                }
                mfr.failureReason = QString("%1 | %2").arg(reason).arg(mfr.failureReason);
                return mfr;
            }

            MultiFrameResult retryMfr = detectMultiFrame(deviceIndex);
            totalMoves++;

            if (retryMfr.valid) {
                if (mode == SearchSuccessMode::ReturnToStart) {
                    double dx_final = target_x - origin_x;
                    double dy_final = target_y - origin_y;
                    convertSearchResultToOrigin(retryMfr, dx_final, dy_final, move.label);

                    LiftUpdateUI(QString("六自由度找码成功 @%1: 换算回原点 (%2, %3)")
                                     .arg(move.label)
                                     .arg(retryMfr.x, 0, 'f', 2)
                                     .arg(retryMfr.y, 0, 'f', 2));
                    qInfo() << QString("六自由度找码成功 @%1: 换算回原点 (%2, %3)")
                                     .arg(move.label)
                                     .arg(retryMfr.x, 0, 'f', 2)
                                     .arg(retryMfr.y, 0, 'f', 2);

                    if (!returnToOrigin()) {
                        retryMfr.valid = false;
                        retryMfr.failureReason = "六自由度找码成功但回原点超时，请人工确认平台位置";
                        emit UpdateSystemInfo(retryMfr.failureReason);
                    }
                } else {
                    LiftUpdateUI(QString("六自由度找码成功 @%1: 停在找到码位置继续闭环")
                                     .arg(move.label));
                    qInfo() << QString("六自由度找码成功 @%1: 停在找到码位置继续闭环")
                                     .arg(move.label);
                }
                return retryMfr;
            }
        }
    }

    // 6. 所有尝试失败：回原点
    LiftUpdateUI("六自由度平移找码失败，正在回原点...");
    bool originRestored = returnToOrigin();

    QString originStatus = originRestored
        ? QString("已回到找码前位置 (%1, %2)。")
              .arg(origin_x, 0, 'f', 1).arg(origin_y, 0, 'f', 1)
        : QString("尝试回到找码前位置 (%1, %2) 时超时，请人工确认平台位置。")
              .arg(origin_x, 0, 'f', 1).arg(origin_y, 0, 'f', 1);
    QString hintMsg = QString(
        "多帧检测失败，六自由度平移找码也失败。\n"
        "%1\n"
        "请人工检查：\n"
        "1. marker 是否被遮挡\n"
        "2. marker_id 是否正确\n"
        "3. 光源 / 曝光是否合适\n"
        "4. 相机标定和 LRU 参数是否正确\n"
        "5. 当前二级高度是否在 z=0 或 z=1700 工作范围")
        .arg(originStatus);
    qInfo() << hintMsg;
    emit UpdateSystemInfo(hintMsg);

    mfr.failureReason = QString("六自由度找码失败(%1次)%2 | %3")
                            .arg(totalMoves)
                            .arg(originRestored ? "" : "，回原点超时")
                            .arg(mfr.failureReason);
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
void Lift::softStop(const AutoLiftDiagnostics& diag)
{
    autolift = false;
    detected_flag = false;
    m_SixDof->stopMotion();

    if (!m_zm->IsSingleIdle(12)) {
        m_zm->SingleVMove(12, Cancel);
    }

    QString msg = diag.stopReason.isEmpty() ? diag.mfr.failureReason : diag.stopReason;
    msg += QString(" | %1 采样%2, 有效%3, 过滤后%4")
               .arg(diag.stageLabel).arg(diag.mfr.sampledFrameCount)
               .arg(diag.mfr.rawValidFrameCount).arg(diag.mfr.validFrameCount);
    msg += QString(" | 残差 x=%1 y=%2 yaw=%3")
               .arg(diag.xRes, 0, 'f', 3).arg(diag.yRes, 0, 'f', 3).arg(diag.yawRes, 0, 'f', 3);
    msg += QString(" | 补偿%1/%2").arg(diag.correctionCount).arg(diag.maxCorrections);
    if (diag.residualGrew) {
        msg += " | 残差变大";
    }
    msg += " | 建议：检查遮挡/反光/光源/相机标定后手动处理";

    LiftUpdateUI(msg);
    emit UpdateSystemInfo(msg);
    qInfo() << "softStop:" << msg;
}

void Lift::onParamsReceived(const LRUInnerParams &params)
{
    // 保留旧字段读取，仅用于兼容旧 JSON；新视觉模型不再使用 x_gap/y_gap 补偿
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

    // 多帧检测（自动流程中允许找码后停在找到位置继续闭环）
    MultiFrameResult mfr = detectMultiFrameWithSixDofSearch(deviceIndex, SearchSuccessMode::StayAtFoundPosition);
    if (!mfr.valid) {
        AutoLiftDiagnostics d;
        d.mfr = mfr;
        d.stopReason = mfr.failureReason;
        softStop(d);
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
    LiftUpdateUI("自动流程内部视觉检测完成");
    return true;
}

bool Lift::auto_StatusModifyLatte()
{
    if (checkCollision_flag == false) {
        LiftUpdateUI("请先开启碰撞检测!");
        return false;
    }
    if (detected_flag == false) {
        LiftUpdateUI("请先进行视觉检测!");
        return false;
    }
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

    // 新模型下：distance_x/y 即 alignError，目标值 = 0
    float xCorr = distance_x * m_cfgCorrectionGain;
    float yCorr = distance_y * m_cfgCorrectionGain;
    float yawCorr = angle * m_cfgCorrectionGain;

    if (qAbs(angle) > m_cfgSettleYawDeg) {
        m_SixDof->posePointMotion(x, y, z, rx, ry, rz - yawCorr, 2, 1);
        qInfo() << "auto_StatusModifyLatte: 调整 yaw";
    } else if (qAbs(distance_x) > m_cfgSettleXyMm || qAbs(distance_y) > m_cfgSettleXyMm) {
        m_SixDof->posePointMotion(x + xCorr, y + yCorr, z, rx, ry, rz, 2, 1);
        qInfo() << "auto_StatusModifyLatte: 调整 xy";
    } else {
        LiftUpdateUI("六自由度平台不需要调整");
    }
    detected_flag = false;
    return true;
}

bool Lift::descent_StatusModifyLatte()
{
    if (checkCollision_flag == false) {
        LiftUpdateUI("请先开启碰撞检测!");
        return false;
    }
    if (detected_flag == false) {
        LiftUpdateUI("请先进行视觉检测!");
        return false;
    }
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

    // 新模型下：distance_x/y 即 alignError，目标值 = 0；下降用全量补偿
    float xCorr = distance_x;
    float yCorr = distance_y;
    float yawCorr = angle;

    if (qAbs(angle) > m_cfgSettleYawDeg) {
        m_SixDof->posePointMotion(x, y, z, rx, ry, rz - yawCorr, 2, 1);
        qInfo() << "descent_StatusModifyLatte: 调整 yaw";
    } else if (qAbs(distance_x) > m_cfgSettleXyMm || qAbs(distance_y) > m_cfgSettleXyMm) {
        m_SixDof->posePointMotion(x + xCorr, y + yCorr, z, rx, ry, rz, 2, 1);
        qInfo() << "descent_StatusModifyLatte: 调整 xy";
    } else {
        LiftUpdateUI("六自由度平台不需要调整");
    }
    detected_flag = false;
    return true;
}
//视觉加六自由度平台-结束
