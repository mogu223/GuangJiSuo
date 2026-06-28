#ifndef LIFT_H
#define LIFT_H
#include "DataType.h"
#include "zmotioncontrol.h"
#include "udpclient.h"
#include <QObject>
#include <QTimer>


using namespace nsTaskMgr;

class Lift: public QObject
{
    Q_OBJECT
public:
    explicit Lift(ZMotionControl* zm,UDPClient* SixDof,QObject *parent = nullptr);

    //力实时信息
    float check_Fx = 0.0f;
    float check_Fy = 0.0f;
    float check_Fz = 0.0f;
    float check_Mx = 0.0f;
    float check_My = 0.0f;
    float check_Mz = 0.0f;
    bool  isforceOver = false;
    bool  istorqueOver = false;

    //平台实时信息
    float SystemX = 0.0f;
    float SystemY = 0.0f;
    float SystemZ = 0.0f;
    float SystemRx = 0.0f;
    float SystemRy = 0.0f;
    float SystemRz = 0.0f;

    //用于碰撞后恢复的系统信息，主窗口调用时更新
    float LastSystemPosition = 0.0f;
    float LastSystemX = 0.0f;
    float LastSystemY = 0.0f;
    float LastSystemZ = 0.0f;
    float LastSystemRx = 0.0f;
    float LastSystemRy = 0.0f;
    float LastSystemRz = 0.0f;

    //阈值
    float ForceXThreshold = 0.0f;
    float ForceYThreshold = 0.0f;
    float ForceZThreshold = 0.0f;
    float TorqueXThreshold = 0.0f;
    float TorqueYThreshold = 0.0f;
    float TorqueZThreshold = 0.0f;

public slots:

    //判断任务状态
    void JudgeTaskStatus(bool status);

    //对应调度系统任务信号的执行槽函数
    void ExeLiftTask(TaskInfo info);

    void moveAbsUp(int axis, float position);

    void moveAbsDown(int axis, float position);

    void moveRelUp(int axis, float distance);

    void moveRelDown(int axis, float distance);

    void moveSpeedUp(int axis);

    void moveSpeedDown(int axis);

    void stopAxis(int axis);

    void emergencyStop();

    //信息交互
    void SetForceData(float fx, float fy, float fz, float mx, float my, float mz);
    void SetPlatformData(float x, float y, float z, float rx, float ry, float rz);

    //碰撞检测
    void CheckCollision();






signals:

    void sigStatusFeedback(eTaskStatus);//任务完成信号

private:

    //任务调度
    eTaskStatus m_TaskStatus;

    bool isComplete;

    //正运动
    ZMotionControl* m_zm;

    //六自由度
    UDPClient* m_SixDof;
};

#endif // LIFT_H
