#include "robotarmxyzmovethread.h"

// RobotArmXYZMoveThread::RobotArmXYZMoveThread(QObject *parent)
//     : QObject{parent}
// {}

void RobotArmXYZMoveThread::stop()
{
    QMutexLocker locker(&mutex);
    move = false;
    cancel=true;
    condition.wakeOne();  // 唤醒线程以便退出
}

void RobotArmXYZMoveThread::run()
{
    while (!cancel)
    {

        // 如果线程被停止了，退出
        if (cancel) break;

        while (move)
        {
            // 如果线程被停止了，退出
            if (cancel) break;

            QMutexLocker locker(&mutex);

            switch(status_MoveXYZ)
            {
            case 0:
                move=false;
                break;
            case 1:
                move=false;
                break;

            }

            // 更新位置

            //MoveTargetPosi_limit(b);

            msleep(100);  // 延时100ms

            // 等待所有轴空闲
            //while (!IsAllAxisIdle()) ;
            locker.unlock(); // 解锁
        }
    }
}
