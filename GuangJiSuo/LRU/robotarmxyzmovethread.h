#ifndef ROBOTARMXYZMOVETHREAD_H
#define ROBOTARMXYZMOVETHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QWaitCondition>
#include "mainwindow.h"
#include "zmotioncontrol.h"
class RobotArmXYZMoveThread : public QThread
{
    Q_OBJECT

public:
    RobotArmXYZMoveThread(QObject *parent = nullptr) : QThread(parent){}

    // 停止线程
    void stop();


protected:
    void run() override;


signals:
    void updateLog(const QString &logMessage);

private:
    bool cancel;
    bool move;
    int status_MoveXYZ;
    int XYZ_flag;
    QMutex mutex;
    QWaitCondition condition;  // 用于线程暂停和恢复
};


#endif // ROBOTARMXYZMOVETHREAD_H
