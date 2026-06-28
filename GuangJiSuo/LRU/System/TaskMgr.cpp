#include "TaskMgr.h"
#include <QDebug>

TaskMgr::TaskMgr(QObject* parent) : QObject(parent)
{
    m_currentStep = Step::Step_Veh_Forward;
    m_errorOccurred = false;
//    processStep();

}


void TaskMgr::startTask() {
    // 启动流程：先执行Vehicle的正向任务
//    emit sigExeVehTask(TaskInfo(1, 0)); // LRU根据实际需求设置

    processStep();
}

//eTaskStatus结构体，反应自己是哪个子系统，执行的任务类型，任务完成状态等
void TaskMgr::slotSubSysStateChanged(eTaskStatus status)
{
    qDebug() << "TaskMgr: Received status from subsystem" << static_cast<int>(status.sys)//子系统
             << ", state:" << static_cast<int>(status.state);//子系统任务完成状态

    m_subSystemStatus[status.sys] = status;//m_subSystemStatus键值对数据类型。键是子系统名称，值是TaskStatus结构体

    //新增:状态改变在主界面打印信息****
    emit sigStatusInfo(status);


    if (status.state == eTaskstate::Complete)
    {
        if (!m_errorOccurred)
        {
            m_currentStep = static_cast<Step>(static_cast<int>(m_currentStep) + 1);
            processStep();
        }
    }
    else if (status.state == eTaskstate::Error)
    {
        qWarning() << "TaskMgr: Error in subsystem" << static_cast<int>(status.sys) << ":" << status.info;
        m_errorOccurred = true;
        m_errorInfo = status.info;

        //新增:发出信号给UI处理错误提示****
        emit sigError(status);
    }
}

void TaskMgr::dispatchTask(eSubSystem sys, int taskType)
{
    //任务信息，包括正反向类型，任务链名称，LRU类型
    TaskInfo taskinfo;

    taskinfo.TaskType = taskType;

    m_subSystemStatus.remove(sys);

    switch (sys)
    {
    case eSubSystem::Vehicle:
        emit sigExeVehTask(taskinfo);
        break;
    case eSubSystem::Levelling:
        emit sigExecLevellingTask(taskinfo);
        break;
    case eSubSystem::MainLift:
        emit sigExecMainLiftTask(taskinfo);
        break;
    case eSubSystem::CoverPlate:
        emit sigExecCoverPlateTask(taskinfo);
        break;
    case eSubSystem::Lift:
        emit sigExecLiftTask(taskinfo);
        break;
    case eSubSystem::Pin:
        emit sigExecPinTask(taskinfo);
        break;
    default:
        qWarning() << "TaskMgr: Unknown subsystem!";
        break;
    }
}
void TaskMgr::processStep()
{
    if (m_errorOccurred)
    {
        qDebug() << "TaskMgr: Task paused due to error. Waiting for resume.";
        return;
    }

    switch (m_currentStep)
    {
    case Step::Step_Veh_Forward:
        dispatchTask(eSubSystem::Vehicle, 1);
        break;
    case Step::Step_Levelling_Forward:
        dispatchTask(eSubSystem::Levelling, 1);
        break;
    case Step::Step_MainLift_Forward:
        dispatchTask(eSubSystem::MainLift, 1);
        break;
    case Step::Step_CoverPlate_Forward:
        dispatchTask(eSubSystem::CoverPlate, 1);
        break;
    case Step::Step_Lift_Forward:
        dispatchTask(eSubSystem::Lift, 1);
        break;
    case Step::Step_Pin:
        dispatchTask(eSubSystem::Pin, 1);
        break;
    case Step::Step_Lift_Backward:
        dispatchTask(eSubSystem::Lift, 2);
        break;
    case Step::Step_CoverPlate_Backward:
        dispatchTask(eSubSystem::CoverPlate, 2);
        break;
    case Step::Step_MainLift_Backward:
        dispatchTask(eSubSystem::MainLift, 2);
        break;
    case Step::Step_Levelling_Backward:
        dispatchTask(eSubSystem::Levelling, 2);
        break;
    case Step::Step_Veh_Backward:
        dispatchTask(eSubSystem::Vehicle, 2);
        break;
    case Step::Step_Done:
        qDebug() << "TaskMgr: All tasks completed.";
        emit sigAllTasksDone();
        break;
    default:
        qWarning() << "TaskMgr: Unknown step.";
        break;
    }
}


//修改：恢复自动调度****
void TaskMgr::resumeFromError()
{
    if (m_errorOccurred)
    {
        qDebug() << "TaskMgr: Resuming from error at step:" << static_cast<int>(m_currentStep);

        if (checkSubsystemErrorsResolved()) {
            m_errorOccurred = false;
            QString Info1= QString("报错已解决!继续当前任务:%1").arg(static_cast<int>(m_currentStep));
            QMessageBox::information(nullptr, "提示", Info1);
            processStep(); // 继续当前步骤
        } else {
            QString Info2= QString("报错未解决!当前任务:%1").arg(static_cast<int>(m_currentStep));
            QMessageBox::information(nullptr, "提示", Info2);
        }
    }
}

//新增：判断报错是否解决****
bool TaskMgr::checkSubsystemErrorsResolved()
{
    for (const auto &sys : m_subSystemStatus.keys()) {
        if (m_subSystemStatus[sys].state == eTaskstate::Error) {
            return false;
        }
    }
    return true;
}




void TaskMgr::EmitsigExeVehTask1()
{
    dispatchTask(eSubSystem::Vehicle, 1);
}
void TaskMgr::EmitsigExeVehTask2()
{
    dispatchTask(eSubSystem::Vehicle, 2);
}


void TaskMgr::EmitsigExeLevelingTask1()
{
    dispatchTask(eSubSystem::Levelling, 1);
}
void TaskMgr::EmitsigExeLevelingTask2()
{
    dispatchTask(eSubSystem::Levelling, 2);
}


void TaskMgr::EmitsigExeMainLiftTask1()
{
    dispatchTask(eSubSystem::MainLift, 1);
}
void TaskMgr::EmitsigExeMainLiftTask2()
{
    dispatchTask(eSubSystem::MainLift, 2);
}


void TaskMgr::EmitsigExeCoverPlateTask1()
{
    dispatchTask(eSubSystem::CoverPlate, 1);
}
void TaskMgr::EmitsigExeCoverPlateTask2()
{
    dispatchTask(eSubSystem::CoverPlate, 2);
}


void TaskMgr::EmitsigExeLiftTask1()
{
    dispatchTask(eSubSystem::Lift, 1);
}
void TaskMgr::EmitsigExeLiftTask2()
{
    dispatchTask(eSubSystem::Lift, 2);
}


void TaskMgr::EmitsigExePinTask()
{
    dispatchTask(eSubSystem::Pin, 1);
}


//自动化流程：实例化TaskMgr *m_TaskMgr,同时实例化各个子系统对象。
//首先调用startTask()函数，其中的 processStep()函数获取初始子系统为AGV小车系统，调用dispatchTask()函数，抛出AGV小车前进的信号。
//然后在主窗口触发小车对象的执行函数ExeVehTask(TaskInfo info)，m_TaskStatus在这里获取前进后退信息。
//然后通过RecvPushHostJsonData(QString jsonData)检测推送的实时数据中的任务状态,m_TaskStatus在这里获取任务状态信息。
//任务完成时，抛出反馈信号sigStatusFeedback(m_TaskStatus)，触发调度对象的slotSubSysStateChanged函数(此时条件满足)，把当前子系统及其状态对应放入容器 QMap<eSubSystem, TaskStatus> m_subSystemStatus中，然后执行下一个子系统任务。
