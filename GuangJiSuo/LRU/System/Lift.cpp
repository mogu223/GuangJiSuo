#include "Lift.h"

Lift::Lift(ZMotionControl* zm,UDPClient* SixDof,QObject *parent) : QObject(parent), m_zm(zm),m_SixDof(SixDof)
{
    m_TaskStatus.sys =eSubSystem::Lift;
}


void Lift::ExeLiftTask(TaskInfo info)
{
    m_TaskStatus.taskinfo.TaskType =info.TaskType;
    JudgeTaskStatus(isComplete);

    if(info.TaskType==1)//正向
    {
        //二级上升执行逻辑待写
    }

    else if(info.TaskType==2)//反向
    {
        //二级下降执行逻辑待写
    }
}


void Lift::JudgeTaskStatus(bool status)
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


//获取六维力信息，进行碰撞检测
void Lift::CheckCollision()
{
    isforceOver = (abs(check_Fx) > ForceXThreshold) || (abs(check_Fy) > ForceYThreshold) || (abs(check_Fz) > ForceZThreshold);
    istorqueOver = (abs(check_Mx) > TorqueXThreshold) || (abs(check_My) > TorqueYThreshold) || (abs(check_Mz) > TorqueZThreshold);

    if (isforceOver || istorqueOver)
    {
        // 退回至碰撞前记录的二级升降的位置
        m_zm->MoveSingleAbs(0, LastSystemPosition);

        // 退回至碰撞前记录的六自由度平台的姿态
        // m_SixDof->set_six_dof_coordinates(LastSystemX,LastSystemY,LastSystemZ,LastSystemRx,LastSystemRy,LastSystemRz);
    }
    else
    {
        //如果未碰撞就把当前的实时信息更新为碰撞前的信息
        LastSystemPosition = m_zm->myZmotionStatus->allAxisStatus[0].posi;//后面改成轴5
        LastSystemX = SystemX;
        LastSystemY = SystemY;
        LastSystemZ = SystemZ;
        LastSystemRx = SystemRx;
        LastSystemRy = SystemRy;
        LastSystemRz = SystemRz;
    }
}

//信息交互
void Lift::SetForceData(float fx, float fy, float fz, float mx, float my, float mz)
{
    check_Fx = fx;
    check_Fy = fy;
    check_Fz = fz;
    check_Mx = mx;
    check_My = my;
    check_Mz = mz;
}

void Lift::SetPlatformData(float x, float y, float z, float rx, float ry, float rz)
{
    SystemX = x;
    SystemY = y;
    SystemZ = z;
    SystemRx = rx;
    SystemRy = ry;
    SystemRz = rz;
}

void Lift::moveAbsUp(int axis, float position)
{
    m_zm->MoveSingleAbs(axis, position);
}

void Lift::moveAbsDown(int axis, float position)
{
    m_zm->MoveSingleAbs(axis, position);
}

void Lift::moveRelUp(int axis, float distance)
{
    m_zm->MoveSingleOpp(axis, distance);
}

void Lift::moveRelDown(int axis, float distance)
{
    m_zm->MoveSingleOpp(axis, -distance);
}

void Lift::moveSpeedUp(int axis)
{
    m_zm->SingleVMove(axis, Forward);
}

void Lift::moveSpeedDown(int axis)
{
    m_zm->SingleVMove(axis, Backward);
}

void Lift::stopAxis(int axis)
{
    m_zm->SingleVMove(axis, Cancel);
}

void Lift::emergencyStop()
{
    m_zm->EmergencyStop();
}
