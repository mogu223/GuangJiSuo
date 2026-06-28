#ifndef COVERPLATE_H
#define COVERPLATE_H
#include "DataType.h"
#include <QObject>
#include <QTimer>
#include <zmotioncontrol.h>


using namespace nsTaskMgr;

class CoverPlate: public QObject
{
    Q_OBJECT
public:
    explicit CoverPlate(ZMotionControl* zm, QObject *parent = nullptr);

public slots:

    //判断任务状态
    void JudgeTaskStatus(bool status);

    //对应调度系统任务信号的执行槽函数
    void ExeCoverPlateTask(TaskInfo info);

    void emergencyStop();

signals:

    void sigStatusFeedback(eTaskStatus);//任务完成信号

private:

    //任务调度
    eTaskStatus m_TaskStatus;

    bool isComplete;

    ZMotionControl* m_zm;


private slots:



};

#endif // COVERPLATE_H
