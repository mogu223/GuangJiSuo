#ifndef LEVELINGSYSTEM_H
#define LEVELINGSYSTEM_H
#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QTimer>
#include <QMessageBox>
#include "zmotioncontrol.h"
#include "DataType.h"
#include <QVector>


using namespace nsTaskMgr;

class LevelingSystem : public QObject
{
    Q_OBJECT

public:
    explicit LevelingSystem(ZMotionControl* zm, QObject *parent = nullptr);

    bool m_isLevel = false;//调平标志位
    bool m_feetAllContact = false;//脚座触地标志位
    bool m_BodytoGround = false;//车身触地标志位

    float angleXforleveling;
    float angleYforleveling;
    float disforleveling;

    //阈值
    float AngleXThreshold;
    float AngleYThreshold;
    float FrontFootCurrentThreshold;
    float RearFootCurrentThreshold;

    //手动调平
    bool m_manualBalance = false;
    bool m_allowEmit = true;

    //状态检测定时器
    QTimer* m_statusMonitorTimer;


public slots:

    // AGV 控制函数
    void FeetToGround();
    void BodyToGround();
    void StartSpeedBodyUp();
    void StopSpeedBodyUp();
    void StartSpeedBodyDown();
    void StopSpeedBodyDown();
    void StopCar();
    void BalanceBody();
    void PosBodyUp();
    void PosBodyDown();

    //对应调度系统任务信号的执行槽函数
    void ExeLevellingTask(TaskInfo info);

    //急停
    void emergencyStop();

    //手动调平
    void IsManualBalance();

    //获取系统状态
    void getSubSystemState();



private:
    // enum MoveMode { Cancel = 2, Forward = 1, Backward = -1};

    ZMotionControl* m_zm;
    QMutex m_statusMutex;
    bool m_feetContact[4] = {false};
    QTimer* m_adjustLevelingTimer = nullptr;

    //任务调度
    eTaskStatus m_TaskStatus;

    //子系统状态判断
    eTaskstate m_lastState = eTaskstate::Ready;
    eTaskstate m_currentState = eTaskstate::Ready;
    QTimer* m_ForCompleteTimer;
    QString m_errorInfo; // 存储错误信息
    QTimer* detectionTimer;
    QTimer* restartTimer;

private slots:

    MoveMode getMotorDirection(int motorId, bool isUp);//isUp代表螺杆的升降

    //子系统状态判断
    void handleStateTransition(eTaskstate newState);
    void monitorSubsystemStatus();


signals:
    void sigStatusFeedback(eTaskStatus);//任务完成信号
    void sigFeetToGround(int);
    void sigBalance();
    void sigRestart();


};

#endif // LEVELINGSYSTEM_H
