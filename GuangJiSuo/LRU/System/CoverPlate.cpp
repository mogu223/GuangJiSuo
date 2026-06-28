#include "CoverPlate.h"
CoverPlate::CoverPlate(ZMotionControl* zm, QObject *parent) : QObject(parent), m_zm(zm)
{
    m_TaskStatus.sys =eSubSystem::CoverPlate;
}

void CoverPlate::ExeCoverPlateTask(TaskInfo info)
{
    m_TaskStatus.taskinfo.TaskType =info.TaskType;
    JudgeTaskStatus(isComplete);

    if(info.TaskType==1)//正向
    {
        //取盖板执行逻辑待写
    }

    else if(info.TaskType==2)//反向
    {
        //盖盖板执行逻辑待写
    }
}

void CoverPlate::JudgeTaskStatus(bool status)
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


void CoverPlate::emergencyStop()
{
    m_zm->EmergencyStop();
}
