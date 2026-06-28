#include "MainLift.h"

MainLift::MainLift(ZMotionControl* zm, QObject *parent) : QObject(parent), m_zm(zm)
{
    m_TaskStatus.sys =eSubSystem::MainLift;
}


void MainLift::ExeMainLiftTask(TaskInfo info)
{
    m_TaskStatus.taskinfo.TaskType =info.TaskType;
    JudgeTaskStatus(isComplete);

    if(info.TaskType==1)//正向
    {
        //一级上升执行逻辑待写
    }

    else if(info.TaskType==2)//反向
    {
        //一级下降执行逻辑待写
    }
}


void MainLift::JudgeTaskStatus(bool status)
{
    QTimer *timer =new QTimer(this);
    connect(timer,&QTimer::timeout,this,[=](){

        if(status)
        {
            m_TaskStatus.state =eTaskstate::Complete;
            emit sigStatusFeedback(m_TaskStatus);
        }
    });
}


void MainLift::moveAbsUp(int axis, float position)
{
    m_zm->MoveSingleAbs(axis, position);
}

void MainLift::moveAbsDown(int axis, float position)
{
    m_zm->MoveSingleAbs(axis, position);
}

void MainLift::moveRelUp(int axis, float distance)
{
    m_zm->MoveSingleOpp(axis, distance);
}

void MainLift::moveRelDown(int axis, float distance)
{
    m_zm->MoveSingleOpp(axis, -distance);
}

void MainLift::moveSpeedUp(int axis)
{
    m_zm->SingleVMove(axis, Forward);
}

void MainLift::moveSpeedDown(int axis)
{
    m_zm->SingleVMove(axis, Backward);
}

void MainLift::stopAxis(int axis)
{
    m_zm->SingleVMove(axis, Cancel);
}

void MainLift::emergencyStop()
{
    m_zm->EmergencyStop();
}
