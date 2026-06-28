#ifndef MAINLIFT_H
#define MAINLIFT_H
#include "DataType.h"
#include "zmotioncontrol.h"
#include <QObject>
#include <QTimer>


using namespace nsTaskMgr;

class MainLift: public QObject
{
    Q_OBJECT
public:
     explicit MainLift(ZMotionControl* zm, QObject *parent = nullptr);

public slots:

    //判断任务状态
    void JudgeTaskStatus(bool status);

    //对应调度系统任务信号的执行槽函数
    void ExeMainLiftTask(TaskInfo info);

    // 绝对位置上升
    void moveAbsUp(int axis, float position);

    // 绝对位置下降
    void moveAbsDown(int axis, float position);

    // 相对位置上升
    void moveRelUp(int axis, float distance);

    // 相对位置下降
    void moveRelDown(int axis, float distance);

    // 速度模式上升
    void moveSpeedUp(int axis);

    // 速度模式下降
    void moveSpeedDown(int axis);

    // 轴运动停止
    void stopAxis(int axis);

    // 急停
    void emergencyStop();


signals:

    void sigStatusFeedback(eTaskStatus);//任务完成信号

private:

    //任务调度
    eTaskStatus m_TaskStatus;

    bool isComplete;

    ZMotionControl* m_zm;

};

#endif // MAINLIFT_H
