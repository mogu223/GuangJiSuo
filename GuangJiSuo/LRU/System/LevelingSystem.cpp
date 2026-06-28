#include"LevelingSystem.h"

LevelingSystem::LevelingSystem(ZMotionControl* zm, QObject *parent)
    : QObject(parent), m_zm(zm)
{
    m_TaskStatus.sys =eSubSystem::Levelling;//绑定子系统

    // 初始化状态监测定时器
    m_statusMonitorTimer = new QTimer(this);
    m_ForCompleteTimer = new QTimer(this);
    detectionTimer = new QTimer(this);//脚座触地
    restartTimer = new QTimer(this);//车身恢复触地
    connect(m_statusMonitorTimer, &QTimer::timeout, this, &LevelingSystem::monitorSubsystemStatus);
    m_ForCompleteTimer->start(200);
}


// 新增：获取子系统实时状态****
void LevelingSystem::getSubSystemState()
{
    //检查是否有轴处于错误状态
    bool hasAxisError = false;
    m_errorInfo.clear();
    for (int i = 0; i < 4; ++i) {
        if (m_zm->GetAxisStatus(i) != MyAxisSatus::正常状态) {
            hasAxisError = true;
            if(!m_errorInfo.isEmpty())
            {
                m_errorInfo += "\n";
            }
            m_errorInfo += QString("轴 %1 错误 : %2").arg(i).arg(AxisStatusQstr(m_zm->GetAxisStatus(i)));
        }
    }

    if (hasAxisError) {
        m_currentState = eTaskstate::Error;
        return;
    }

    //任意一轴运动，视为Running状态
    bool anyAxisMoving = false;
    for (int i = 0; i < 4; ++i) {
        if (m_zm->GetAxisMType(i) != AxisMType::Idle) {
            anyAxisMoving = true;
            break;
        }
    }

    if (anyAxisMoving) {
        m_currentState = eTaskstate::Running;
        return;
    }

    // 全部轴静止，触发标志位为Complete状态，未触发且为正常状态为ready状态
    //IsSingleIdle 获取轴运动状态，0运行中，1运动停止
    bool allAxesIdle = true;
    for (int i = 0; i < 4; ++i) {
        if (m_zm->GetAxisMType(i) != AxisMType::Idle) {
            allAxesIdle = false;
            break;
        }
    }

    if (allAxesIdle) {
        // 检查是否已经完成调平
        if (m_isLevel || m_BodytoGround || m_manualBalance) {
            m_currentState = eTaskstate::Complete;
            return;
        }
        else
        {
            m_currentState = eTaskstate::Ready;
            return;
        }
    }
}

// 新增：处理状态转换****
void LevelingSystem::handleStateTransition(eTaskstate newState)
{
    bool StatusChange = false;

    if (m_lastState!= newState) StatusChange = true;
    else if(newState == eTaskstate::Error && m_lastState == eTaskstate::Error)
    {
        if(m_TaskStatus.info != m_errorInfo) StatusChange = true;
    }

    if(StatusChange)
    {
        m_lastState = newState;

        //进入新状态，清除错误信息
        m_TaskStatus.info.clear();

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
            if (!m_allowEmit) {
                connect(m_ForCompleteTimer, &QTimer::timeout, this, [=]() {
                    if (m_allowEmit) {
                        m_ForCompleteTimer->stop();
                        emit sigStatusFeedback(m_TaskStatus);
                    }
                });
                return;
            }
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


// 新增：状态监测定时器回调****
void LevelingSystem::monitorSubsystemStatus()
{
    getSubSystemState();
    handleStateTransition(m_currentState);
}

//手动调平
void LevelingSystem::IsManualBalance()
{
    //每次判断前为了防止上一次判断结果的影响，手动置为假
    m_isLevel = false;

    // 根据倾角传感器判断是否调平
    if (qAbs(angleXforleveling) <= 0.1 && qAbs(angleYforleveling) <= 0.1)
    {
        m_isLevel = true;
        m_manualBalance = true;
        QMessageBox::information(nullptr, "提示", "可恢复自动调度！");
    }
    else if(m_BodytoGround)
    {
        m_manualBalance = true;
        QMessageBox::information(nullptr, "提示", "可恢复自动调度！");
    }
    else
    {
        QMessageBox::information(nullptr, "提示", "还未调平！");
    }
}

MoveMode LevelingSystem::getMotorDirection(int motorId, bool isUp)
{
    if (motorId == 0 || motorId == 3) {
        return isUp ? Forward : Backward;
    } else {
        return isUp ? Backward : Forward;
    }
}


void LevelingSystem::ExeLevellingTask(TaskInfo info)
{
    m_TaskStatus.taskinfo.TaskType = info.TaskType;//绑定正反向

    QTimer *timer = new QTimer(this);

    enum class LevelingState {
        ForContact,  // 检测脚座触地
        ForBalance   // 执行调平
    };
    LevelingState CurrentState = LevelingState::ForContact;

    if(info.TaskType==1)//正向
    {
       FeetToGround();//内部有定时器，检测到脚座触地，m_feetAllContact置为真
        connect(timer, &QTimer::timeout, this, [&]() {
            switch (CurrentState) {
            case LevelingState::ForContact:
                if (m_feetAllContact) {
                    BalanceBody();//内部有定时器,调平完成，m_isLevel置为真
                    CurrentState = LevelingState::ForBalance;
                }
                break;

            case LevelingState::ForBalance:
                if (m_isLevel) {
                    timer->stop();
                }
                break;
            }
        });
    }

    else if(info.TaskType==2)//反向
    {
        BodyToGround();
        connect(timer, &QTimer::timeout, this, [=]() {
            if (m_BodytoGround) {
                timer->stop();
            }
        });
    }

    timer->start(200);
}


//防虚脚函数
void LevelingSystem::FeetToGround()
{
    // QMutexLocker locker(&m_statusMutex);

    //这里要加入一个动态阈值逻辑，一级升降重量被两个传感器平分，一级升降丝杆，二级升降和LRU重量被四个传感器平分
    std::vector<float>CurrentThresholds = {3.3,3.0,5.8,5.8};

    enum class DetectionState { IDLE, POSITION, CONTACT };
    static DetectionState currentState = DetectionState::IDLE;

    for (int i = 0; i < 4; ++i) {
        m_feetContact[i] = false;
    }

    //防止上次结果的影响，重置状态
    m_feetAllContact = false;

    currentState = DetectionState::POSITION;

    for (int i = 0; i < 4; ++i) {
        m_zm->SetAxisSpeed(i, 1.0);
        m_zm->SetAxisUnits(i,1310720);
        m_zm->SetAxisAccel(i,30);
        m_zm->SetAxisDecel(i,150);
        m_zm->SetAxisFSLimit(i,2000);
        m_zm->SetAxisRSLimit(i,-2000);
    }

    for (int i = 0; i < 4; ++i) {
        m_zm->MoveSingleAbs(i, 0);
    }

    connect(detectionTimer, &QTimer::timeout, this, [=]() {
        switch (currentState) {
        case DetectionState::POSITION: {
            bool allPositionsReached = true;
            for (int i = 0; i < 4; ++i) {
                if (abs(m_zm->myZmotionStatus->allAxisStatus[i].posi) > 0.1) {
                    allPositionsReached = false;
                    break;
                }
            }

            if (allPositionsReached) {
                for (int i = 0; i < 4; ++i) {
                    m_zm->SingleVMove(i, Cancel);
                    m_zm->SetAxisSpeed(i, 0.1);
                    m_zm->SingleVMove(i, getMotorDirection(i, false));
                }
                currentState = DetectionState::CONTACT;
            }
            break;
        }
        case DetectionState::CONTACT: {
            bool allContact = true;
            for (int i = 0; i < 4; ++i) {
                float current = m_zm->GetMotorCurrent(i);
                if(abs(current) >= CurrentThresholds[i]) {
                    m_zm->SingleVMove(i, Cancel);
                    m_feetContact[i] = true;
                    //抛出一个带有i的信号，告诉主界面更新触地标志位
                    emit sigFeetToGround(i);
                }
                allContact &= m_feetContact[i];
            }
            if (allContact)
            {
                detectionTimer->stop();
                m_feetAllContact = true;//脚座触地
                QMessageBox::information(nullptr, "提示", "脚座全部触地,请开始调平");
            }
            break;
        }
        default: break;
        }
    });
    detectionTimer->start(100);
}



//倾角传感器调平
void LevelingSystem::BalanceBody()
{
    m_adjustLevelingTimer = new QTimer(this);
    QMutexLocker locker(&m_statusMutex);

    if(!m_feetAllContact){
        QMessageBox::warning(nullptr, "警告", "脚座未全部触地，无法调平！");
        return;
    }

    m_isLevel = false;//每次判断前为了防止上一次判断结果的影响，手动置为假

    static int adjustmentPhase = 0;
    static QVector<int> currentMotors;

    connect(m_adjustLevelingTimer, &QTimer::timeout, this, [this]() {
        auto shouldStop = [&](float current) { return qAbs(current) <= AngleXThreshold; };

        auto stopAllMotors = [&]() {
            for(int id : currentMotors) { m_zm->SingleVMove(id, Cancel); }
            currentMotors.clear();
        };

        auto startNewMotors = [&](const QVector<int>& motors, bool isUp) {
            stopAllMotors();
            currentMotors = motors;
            for(int id : motors) {
                m_zm->SetAxisSpeed(id, 0.1);
                m_zm->SingleVMove(id, getMotorDirection(id, isUp));
            }
        };

        float angleX_deg = angleXforleveling;
        float angleY_deg = angleYforleveling;

        switch(adjustmentPhase) {
        case 0: {
            bool frontTilt = angleX_deg < -AngleXThreshold;
            bool rearTilt  = angleX_deg > AngleXThreshold;
            bool leftTilt  = angleY_deg < -AngleYThreshold;
            bool rightTilt = angleY_deg > AngleYThreshold;

            if(frontTilt && leftTilt) {
                startNewMotors({0,1}, false);
                adjustmentPhase = 1;
            } else if(frontTilt && rightTilt) {
                startNewMotors({0,1}, false);
                adjustmentPhase = 1;
            } else if(rearTilt && leftTilt) {
                startNewMotors({2,3}, false);
                adjustmentPhase = 1;
            } else if(rearTilt && rightTilt) {
                startNewMotors({2,3}, false);
                adjustmentPhase = 1;
            } else if(frontTilt && !leftTilt && !rightTilt) {
                startNewMotors({0,1}, false);
                adjustmentPhase = 1;
            } else if(rearTilt && !leftTilt && !rightTilt) {
                startNewMotors({2,3}, false);
                adjustmentPhase = 1;
            } else if(leftTilt && !frontTilt && !rearTilt) {
                startNewMotors({0,2}, false);
                adjustmentPhase = 2;
            } else if(rightTilt && !frontTilt && !rearTilt) {
                startNewMotors({1,3}, false);
                adjustmentPhase = 2;
            }
            else{
                m_isLevel = true;
                QMessageBox::information(nullptr, "提示", "无需调平，车身升降就绪！");
                m_adjustLevelingTimer->stop();
                //抛出调平信号
                emit sigBalance();
            }
            break;
        }
        case 1: {
            if(shouldStop(angleX_deg)) {
                stopAllMotors();
                if(qAbs(angleY_deg) > AngleYThreshold) {
                    if(angleY_deg < 0) startNewMotors({0,2}, false);
                    else startNewMotors({1,3}, false);
                    QMessageBox::information(nullptr, "提示", "X轴调平完成！");
                    adjustmentPhase = 2;
                } else {
                    adjustmentPhase = 0;
                    QMessageBox::information(nullptr, "提示", "调平完成，车身升降就绪！");
                    m_isLevel = true;
                    //抛出调平信号
                    emit sigBalance();
                    m_adjustLevelingTimer->stop();
                }
            }
            break;
        }
        case 2: {
            if(shouldStop(angleY_deg)) {
                stopAllMotors();
                adjustmentPhase = 0;
                m_isLevel = true;
                QMessageBox::information(nullptr, "提示", "调平完成，车身升降就绪！");
                 //抛出调平信号
                emit sigBalance();
                m_adjustLevelingTimer->stop();
            }
            break;
        }
        }
    });
    m_adjustLevelingTimer->start(200);
}



void LevelingSystem::BodyToGround()
{
    m_BodytoGround = false;//每次判断前为了防止上一次判断结果的影响，手动置为假

    for (int i = 0; i < 4; ++i) {
        m_feetContact[i] = true;
    }

    for(int i=0; i<4; ++i){
        m_zm->SetAxisSpeed(i, 1.5);
        if(i==0 || i==3)
        {
            m_zm->MoveSingleAbs(i,10);
        }
        else
        {
            m_zm->MoveSingleAbs(i,-10);
        }
    }

    connect(restartTimer, &QTimer::timeout, this, [=]() {
        bool notContact = true;
        for(int i=0; i<4; ++i){
            if(i==0 || i==3)
            {
                if(m_zm->myZmotionStatus->allAxisStatus[i].posi>=0)
                    m_feetContact[i] = false;
            }
            else
            {
                if(m_zm->myZmotionStatus->allAxisStatus[i].posi<=0)
                    m_feetContact[i] = false;
            }
            notContact &= !m_feetContact[i];
        }
        if(notContact)
            {
                m_isLevel = false;
                m_BodytoGround = true;
                emit sigRestart();//标志位复原信号
                restartTimer->stop();
            }
    });
    restartTimer->start(100);
}


void LevelingSystem::StartSpeedBodyUp()
{
    QMutexLocker locker(&m_statusMutex);
    QTimer *timer = new QTimer(this);

    if(!m_isLevel){
        QMessageBox::warning(nullptr, "警告", "请先完成调平！");
        return;
    }

    for(int i=0; i<4; ++i) {
        m_zm->SetAxisSpeed(i, 1.5);
        m_zm->SingleVMove(i, getMotorDirection(i, false));
    }

    connect(timer, &QTimer::timeout, this, [=]() {
    for(int i=0; i<4; ++i) {
        if(i==0 || i==3){
            if(m_zm->myZmotionStatus->allAxisStatus[i].posi<=-80){
                m_zm->SingleVMove(i,Cancel);
                QMessageBox::warning(nullptr, "警告", "位置已达上限！");
                timer->stop();
                return;
            }
        }
        else{
            if(m_zm->myZmotionStatus->allAxisStatus[i].posi>=80){
                m_zm->SingleVMove(i,Cancel);
                QMessageBox::warning(nullptr, "警告", "位置已达上限！");
                timer->stop();
                return;
            }
        }
    }});

    timer->start(200);
}


void LevelingSystem::StopSpeedBodyUp()
{
    StopCar();
}


void LevelingSystem::StartSpeedBodyDown()
{
    QMutexLocker locker(&m_statusMutex);
    QTimer *timer = new QTimer(this);

    if(!m_isLevel){
        QMessageBox::warning(nullptr, "警告", "请先完成调平！");
        return;
    }
    for(int i=0; i<4; ++i) {
        m_zm->SetAxisSpeed(i, 1.5);
        m_zm->SingleVMove(i, getMotorDirection(i, true));
    }

    //持续检测是否超过位置限制
    connect(timer, &QTimer::timeout, this, [=]() {
    for(int i=0; i<4; ++i) {
        if(i==0 || i==3){
            if(m_zm->myZmotionStatus->allAxisStatus[i].posi>=0){
                m_zm->SingleVMove(i,Cancel);
                QMessageBox::warning(nullptr, "警告", "位置已达下限！");
                timer->stop();
                return;
            }
        }
        else{
            if(m_zm->myZmotionStatus->allAxisStatus[i].posi<=0){
                m_zm->SingleVMove(i,Cancel);
                QMessageBox::warning(nullptr, "警告", "位置已达下限！");
                timer->stop();
                return;
            }
        }
    } });

    timer->start(200);
}


void LevelingSystem::StopSpeedBodyDown()
{
    StopCar();
}


void LevelingSystem::StopCar()
{
    for (int i = 0; i < 4; ++i) {
        if(m_zm->GetConnectStatus()) {
            m_zm->SingleVMove(i, Cancel);
        }
    }
}


void LevelingSystem::PosBodyUp()
{
    QMutexLocker locker(&m_statusMutex);
    QTimer *timer = new QTimer(this);

    if(!m_isLevel){
        QMessageBox::warning(nullptr, "警告", "请先完成调平！");
        return;
    }
    for(int i=0; i<4; ++i) {
        m_zm->SetAxisSpeed(i, 1.5);
    }
    float dis = disforleveling;
    m_zm->MoveSingleOpp(0,-dis);
    m_zm->MoveSingleOpp(1,dis);
    m_zm->MoveSingleOpp(2,dis);
    m_zm->MoveSingleOpp(3,-dis);

    connect(timer, &QTimer::timeout, this, [=]() {
        for(int i=0; i<4; ++i) {
            if(i==0 || i==3){
                if(m_zm->myZmotionStatus->allAxisStatus[i].posi<=-80){
                    m_zm->SingleVMove(i,Cancel);
                    QMessageBox::warning(nullptr, "警告", "位置已达上限！");
                    timer->stop();
                    return;
                }
            }
            else{
                if(m_zm->myZmotionStatus->allAxisStatus[i].posi>=80){
                    m_zm->SingleVMove(i,Cancel);
                    QMessageBox::warning(nullptr, "警告", "位置已达上限！");
                    timer->stop();
                    return;
                }
            }
        }});

    timer->start(200);
}


void LevelingSystem::PosBodyDown()
{
    QMutexLocker locker(&m_statusMutex);
    QTimer *timer = new QTimer(this);

    if(!m_isLevel){
        QMessageBox::warning(nullptr, "警告", "请先完成调平！");
        return;
    }
    for(int i=0; i<4; ++i) {
        m_zm->SetAxisSpeed(i, 1.5);
    }
    float dis = disforleveling;
    m_zm->MoveSingleOpp(0,dis);
    m_zm->MoveSingleOpp(1,-dis);
    m_zm->MoveSingleOpp(2,-dis);
    m_zm->MoveSingleOpp(3,dis);

    connect(timer, &QTimer::timeout, this, [=]() {
        for(int i=0; i<4; ++i) {
            if(i==0 || i==3){
                if(m_zm->myZmotionStatus->allAxisStatus[i].posi<=0){
                    m_zm->SingleVMove(i,Cancel);
                    QMessageBox::warning(nullptr, "警告", "位置已达下限！");
                    timer->stop();
                    return;
                }
            }
            else{
                if(m_zm->myZmotionStatus->allAxisStatus[i].posi>=0){
                    m_zm->SingleVMove(i,Cancel);
                    QMessageBox::warning(nullptr, "警告", "位置已达下限！");
                    timer->stop();
                    return;
                }
            }
        } });

    timer->start(200);
}

//急停
void LevelingSystem::emergencyStop()
{
    m_zm->EmergencyStop();
}


// // 车身恢复触地
// void MainWindow::on_btn_BodyToGround_clicked()
// {
//     QTimer *timer = new QTimer(this);

//     // QLineEdit * sensor[] ={ui->sensor0,ui->sensor1,ui->sensor2,ui->sensor3};

//     QLabel * labels[] ={ui->lbl_Symbol0,ui->lbl_Symbol1,ui->lbl_Symbol2,ui->lbl_Symbol3};

//     for(int i=0; i<4; ++i){
//         zm->SetAxisSpeed(i, 3.0);
//         if(i==0 || i==3){
//             zm->MoveSingleAbs(i,30);
//         }
//         else{
//             zm->MoveSingleAbs(i,-30);
//         }
//     }

//     connect(timer, &QTimer::timeout, this, [=]() {

//         bool allContact = true;

//         for(int i=0; i<4; ++i){

//             //小车触地的过程，小于阈值恢复初始状态
//             if(i==0 || i==3)
//             {
//                 if(allAxisStatus[i].posi>=0)
//                 {
//                     m_feetContact[i] =false ;
//                     labels[i]->setStyleSheet("background-color: green;");//未触地标志位设为绿
//                 }

//             }
//             else
//             {
//                 if(allAxisStatus[i].posi<=0)
//                 {
//                     m_feetContact[i] =false ;
//                     labels[i]->setStyleSheet("background-color: green;");//未触地标志位设为绿
//                 }

//             }

//             allContact &= !m_feetContact[i];
//         }


//         if(allContact)
//         {
//             timer->stop();
//         }

//     });


//     // connect(timer, &QTimer::timeout, this, [=]() {
//     //     for(int i=0; i<4; ++i){

//     //         float force = sensor[i]->text().toFloat();

//     //         //小车触地的过程，小于阈值恢复初始状态
//     //         if(abs(force) <= 200)
//     //         {
//     //             m_feetContact[i] =false ;
//     //             labels[i]->setStyleSheet("background-color: green;");//未触地标志位设为绿
//     //             timer->stop();
//     //         }
//     //     }
//     // });

//     timer->start(200);
// }
