#ifndef TASKMGR_H
#define TASKMGR_H
#include "DataType.h"
#include <QObject>
#include <QMap>
#include <QMessageBox>


using namespace nsTaskMgr;

class TaskMgr: public QObject
{
    Q_OBJECT
public:
    TaskMgr(QObject* parent = nullptr);
    void startTask();
    void resumeFromError();

    //错误信号
    bool m_errorOccurred = false;

signals:
    //to sub system
    void sigExeVehTask(TaskInfo);
    void sigExecLevellingTask(TaskInfo);
    void sigExecMainLiftTask(TaskInfo);
    void sigExecCoverPlateTask(TaskInfo);
    void sigExecLiftTask(TaskInfo);
    void sigExecPinTask(TaskInfo);
    //to mainwindows
    void sigAllTasksDone();
    void sigError(eTaskStatus);
    void sigStatusInfo(eTaskStatus);



public slots:
    //from subsystem
    void slotSubSysStateChanged(eTaskStatus);

    //界面调用
    void EmitsigExeVehTask1();
    void EmitsigExeVehTask2();
    void EmitsigExeLevelingTask1();
    void EmitsigExeLevelingTask2();
    void EmitsigExeMainLiftTask1();
    void EmitsigExeMainLiftTask2();
    void EmitsigExeCoverPlateTask1();
    void EmitsigExeCoverPlateTask2();
    void EmitsigExeLiftTask1();
    void EmitsigExeLiftTask2();
    void EmitsigExePinTask();

    //检测错误是否解决
    bool checkSubsystemErrorsResolved();

private:
    enum class Step
    {
        Step_Veh_Forward,//小车运动
        Step_Levelling_Forward,//调平
        Step_MainLift_Forward,//一级上升
        Step_CoverPlate_Forward,//取盖板
        Step_Lift_Forward,//二级上升
        Step_Pin,//拔销
        Step_Lift_Backward,//二级下降
        Step_CoverPlate_Backward,//盖盖板
        Step_MainLift_Backward,//一级下降
        Step_Levelling_Backward,//小车触地
        Step_Veh_Backward,//小车退回
        Step_Done//完成
    };

    inline QString StepToString(Step step)
    {
        switch (step)
        {
        case Step::Step_Veh_Forward:       return "AGV驶至终点";
        case Step::Step_Levelling_Forward: return "车身调平";
        case Step::Step_MainLift_Forward:  return "一级抬升";
        case Step::Step_CoverPlate_Forward: return "取盖板";
        case Step::Step_Lift_Forward:      return "二级抬升";
        case Step::Step_Pin:               return "拔销";
        case Step::Step_Lift_Backward:     return "二级下降";
        case Step::Step_CoverPlate_Backward: return "盖盖板";
        case Step::Step_MainLift_Backward: return "一级下降";
        case Step::Step_Levelling_Backward: return "车身触地";
        case Step::Step_Veh_Backward:      return "AGV退回原点";
        case Step::Step_Done:              return "任务完成";
        }
    }

    void startNextStep();
    void dispatchTask(eSubSystem sys, int taskType);
    void processStep();

    // 状态跟踪
    QMap<eSubSystem, eTaskStatus> m_subSystemStatus;

    Step m_currentStep;
    QString m_errorInfo;

};

#endif // TASKMGR_H
