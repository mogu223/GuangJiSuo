#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QThread>
/**
*@brief Qt总线初始化
*@param[in] 槽位号,本地轴数目,总线轴起始轴号，PDO模式
*@return 0：执行正常、    非0：执行异常
*@ingroup
*@see
*@note
*/
int EcatInit(int SlotId,int LocalAxisNum,int BusAxisStartId,int ProFileMode)
{
    char CmdBuff[64]={0},ReceBuff[256];
    float VirtualAxises=0,RealAxises=0; //虚拟轴和实轴数目
    int EcatInitStatus=-1,Err=0;
    int TimeOut=3000,TimeOutFlag=3000;
    float NodeNum=0;
    //延迟5秒，等待驱动器上电，不同驱动器自身上电时间不同，具体根据驱动器调整延时
    QThread::sleep(3);
    //获取总线通讯周期
    Err = ZAux_Execute(g_handle,"?SERVO_PERIOD", ReceBuff,256 );
    qDebug()<<"总线通讯周期(us)："<<ReceBuff;
    //初始化还原轴类型
    Err = ZAux_Direct_Rapidstop(g_handle,2);
    Err = ZAux_Execute(g_handle,"Table(0)=SYS_ZFEATURE(0)", ReceBuff,256 );
    Err = ZAux_Direct_GetTable(g_handle, 0, 1, &VirtualAxises);
    for(int i=0;i<VirtualAxises;i++)
    {
        Err = ZAux_Direct_SetAxisAddress(g_handle,i,0);
        Err = ZAux_Direct_SetAxisEnable(g_handle,i,0);
        Err = ZAux_Direct_SetAtype(g_handle,i,0);
        //等待轴停止
        int Idle=0;
        TimeOutFlag =TimeOut;
        while(TimeOutFlag>0)
        {
            Err = ZAux_Direct_GetIfIdle(g_handle,i,&Idle);
            if(Idle)
            {
                break;
            }
            QThread::msleep(10);
            TimeOutFlag = TimeOutFlag-10;
        }
    }
    //本地轴重新映射
    for(int i=0;i<LocalAxisNum;i++)
    {
        Err = ZAux_Direct_SetAxisAddress(g_handle,i,(-1<<16)+i);
        Err = ZAux_Direct_SetAtype(g_handle,i,1);
    }
    //停止总线
    sprintf(CmdBuff,"SLOT_STOP(%d)",SlotId);
    Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
    QThread::msleep(200);
    //总线时钟优化
    Err = ZAux_Execute(g_handle,"SYSTEM_ZSET = SYSTEM_ZSET OR 128", ReceBuff,256 );
    //扫描总线
    sprintf(CmdBuff,"SLOT_SCAN(%d) ?return",SlotId);
    Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
    QThread::sleep(3);
    ReceBuff[2]=0;
    //等待总线扫描完成
    if(0 == strcmp("-1",ReceBuff))
    {

        TimeOutFlag = TimeOut;
        while(TimeOutFlag>0)
        {
            sprintf(CmdBuff,"Table(0)=NODE_COUNT(%d)",SlotId);
            Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
            Err = ZAux_Direct_GetTable(g_handle, 0, 1, &NodeNum);
            if(NodeNum>0)
            {
                break;
            }
            QThread::msleep(10);
            TimeOutFlag = TimeOutFlag-10;
        }
        qDebug()<<"总线扫描成功，连接设备数："<<NodeNum;
        //初始化节点
        if(NodeNum>=0)
        {
            int BusAxis_Num=0; //总线轴总数，从0开始计数
            for(int i=0; i<NodeNum;i++)
            {
                //读取节点轴数
                float NodeAxisNum=0;
                sprintf(CmdBuff,"Table(0)=NODE_AXIS_COUNT(%d,%d)",SlotId,i);
                Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
                Err = ZAux_Direct_GetTable(g_handle, 0, 1, &NodeAxisNum);
                for(int j=0;j<NodeAxisNum;j++)
                {
                    Err = ZAux_Direct_SetAxisAddress(g_handle,BusAxisStartId+BusAxis_Num,BusAxis_Num+1);
                    Err = ZAux_Direct_SetAtype(g_handle,BusAxisStartId+BusAxis_Num,65);
                    sprintf(CmdBuff,"DRIVE_PROFILE(%d) = %d",BusAxisStartId+BusAxis_Num,ProFileMode);
                    Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
                    sprintf(CmdBuff,"DISABLE_GROUP(%d)",BusAxisStartId+BusAxis_Num);
                    Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
                    BusAxis_Num = BusAxis_Num+1;
                }
            }
            EcatInitStatus = 0;//总线扫描完成
            qDebug()<<"轴扫描映射完成，连接总线轴数："<<BusAxis_Num;
            //开启总线
            QThread::msleep(100);
            sprintf(CmdBuff,"SLOT_START(%d) ?return",SlotId);
            Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
            ReceBuff[2]=0;
            if(0 == strcmp("-1",ReceBuff))
            {
                qDebug()<<"总线开启正常";
                QThread::sleep(3);//延迟3秒，等待驱动器时钟同步
                int AxisList[1];
                for(int i=BusAxisStartId;i<BusAxisStartId+BusAxis_Num;i++)
                {
                    AxisList[0]=i;
                    Err = ZAux_Direct_Base(g_handle, 1,AxisList);
                    Err = ZAux_Execute(g_handle,"DRIVE_CLEAR(0)", ReceBuff,256 );
                    QThread::msleep(10);
                    sprintf(CmdBuff,"DRIVE_CONTROLWORD(%d) = 128 ",i);
                    Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
                    QThread::msleep(10);
                    sprintf(CmdBuff,"DRIVE_CONTROLWORD(%d)=6 ",i);
                    Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
                    QThread::msleep(10);
                    sprintf(CmdBuff,"DRIVE_CONTROLWORD(%d)=15 ",i);
                    Err = ZAux_Execute(g_handle,CmdBuff, ReceBuff,256 );
                    QThread::msleep(10);
                }
                QThread::msleep(100);
                Err = ZAux_Execute(g_handle,"DATUM(0)", ReceBuff,256 );
                qDebug()<<"控制器报警清除完成";
                QThread::msleep(1000);
                Err = ZAux_Execute(g_handle,"WDOG = 1", ReceBuff,256 );
                for(int i=BusAxisStartId;i<BusAxisStartId+BusAxis_Num;i++)
                {
                    ZAux_Direct_SetAxisEnable(g_handle,i,1);
                    QThread::msleep(10);
                }
                qDebug()<<"伺服使能完成";
                EcatInitStatus = 1;//总线初始化完成
            }
            else
            {
                EcatInitStatus=-1;
                qDebug()<<"总线开启异常";
            }
        }
    }
    return EcatInitStatus;
}
/**
*@brief 等待控制器函数执行完成
*@param[in] 函数执行完成的标志位变量名字符串（该变量在Basic定义）
*@return 0：执行正常、    非0：执行异常
*@ingroup
*@see
*@note
*/
int WaitContrFunctComple(const char *cmdbuff, int TimeOut)
{
    int FunctCompleFlag=0;  //函数执行标志 1：执行完成 0：执行未完成
    int Count=0;            //计时器
    int Err=0;              //Zmotion函数返回值
    //等待控制器函数执行完成
    while(0 == FunctCompleFlag)
    {
        Err = ZAux_Direct_GetVariableInt(g_handle,cmdbuff,&FunctCompleFlag);
        QThread::msleep(10);
        Count++;
        if((TimeOut/10) < Count)
        {
            //等待时间大于5s退出循环
            Err=1;
            break;
        }
    }
    //如果FunctCompleFlag 不等于1不是Basic那边函数执行有错误
    if(FunctCompleFlag != 1 )
    {
        Err = FunctCompleFlag;
    }
    return Err;
}
