#ifndef SCVEHICLE_H
#define SCVEHICLE_H
#include "SCStatusTcp.h"
#include "common/Worker.h"
#include "VehStatemachine.h"
#include "DataType.h"
#include <QMessageBox>


using namespace nsTaskMgr;
using namespace nVehicleDataType;

class SCVehicle: public QObject
{
     Q_OBJECT
public:
     explicit SCVehicle(QObject *parent = 0);
    ~SCVehicle();

    int connectPushHost(const QString &ip, quint16 port);
    void ClosePushHostConnection();
    int connectNavigateHost(const QString &ip, quint16 port);
    void CloseNavigateConnection();
    int connectConfigureHost(const QString &ip, quint16 port);
    void CloseConfigureConnection();
    int connectControlHost(const QString &ip, quint16 port);
    void CloseControlConnection();
    bool isConnectedPushHost();
    bool isConnectedNavigateHost();
    bool isConnectedConfigureHost();
    bool isConnectedControlHost();
    bool SendData2PushHost(uint16_t sendCommand,
                             const QByteArray &jsonData,
                             const QByteArray &sendData,
                             uint16_t &number, uint8_t byte15);
    bool SendData2NavigateHost(uint16_t sendCommand,
                             const QByteArray &jsonData,
                             const QByteArray &sendData,
                             uint16_t &number, uint8_t byte15);
    bool SendData2ConfigureHost(uint16_t sendCommand,
                               const QByteArray &jsonData,
                               const QByteArray &sendData,
                               uint16_t &number, uint8_t byte15);//配置API，绑定鼠标事件
    bool SendData2ControlHost(uint16_t sendCommand,
                                const QByteArray &jsonData,
                                const QByteArray &sendData,
                                uint16_t &number, uint8_t byte15);//控制API:AGV重定位,上传并推送地图
    void sendControlCommandToVehicle(const QString& target);

    bool uploadMapToRobot(const QString& mapFilePath);//上传并推送地图到AGV
    bool relocateRobot(bool isAuto, double x, double y, double angle, double length, bool home);//AGV重定位
    bool pauseCurrentNavigation();//  暂停当前导航
    bool resumeCurrentNavigation();// 继续当前导航
    bool cancelCurrentNavigation();// 取消当前导航
    void IsManualNavigate(const QString& station);

    bool m_manualNavigate = false;

    //任务调度
    eTaskStatus m_TaskStatus;


private:
    bool parseJsonToVehicleSts(const QString& jsonString, VehicleSts& vehSts);

public slots:
    void RecvPushHostStrData(QString info);
    void RecvPushHostVehicleData(bool ,int ,QByteArray ,QByteArray ,int ,int );
    void RecvPushHostJsonData(QString info);
    void PushHostSvrStateChanged(QAbstractSocket::SocketState state);
    void PushHostSvrTcpError(QAbstractSocket::SocketError error);

    void RecvNavigateStrData(QString info);
    void RecvNavigateVehicleData(bool ,int ,QByteArray ,QByteArray ,int ,int );
    void RecvNavigateJsonData(QString info);
    void NavigateSvrStateChanged(QAbstractSocket::SocketState state);
    void NavigateSvrTcpError(QAbstractSocket::SocketError error);


    //配置API，绑定鼠标事件
    void RecvConfigureStrData(QString info);
    void RecvConfigureVehicleData(bool ,int ,QByteArray ,QByteArray ,int ,int );
    void RecvConfigureJsonData(QString info);
    void ConfigureSvrStateChanged(QAbstractSocket::SocketState state);
    void ConfigureSvrTcpError(QAbstractSocket::SocketError error);


    //控制API，AGV重定位
    void RecvControlStrData(QString info);
    void RecvControlVehicleData(bool ,int ,QByteArray ,QByteArray ,int ,int );
    void RecvControlJsonData(QString info);
    void ControlSvrStateChanged(QAbstractSocket::SocketState state);
    void ControlSvrTcpError(QAbstractSocket::SocketError error);

    //对应调度系统任务信号的执行槽函数
    void ExeVehTask(TaskInfo info);

    void stateChanged(QAbstractSocket::SocketState state);
    void receiveTcpError(QAbstractSocket::SocketError error);


signals:
    void sigPrintInfo(QString);
//  void sigChangedText(bool ,int ,QByteArray ,QByteArray ,int ,int );
    void sigNaviInfo(QString);
    void sigConfInfo(QString);
    void sigContInfo(QString);
    void sigVehSts(VehicleSts);
    void sigVehTcpStateChanged(TcpSvrType,QAbstractSocket::SocketState);
    void sigUILog(QString info);
    void sigStatusFeedback(eTaskStatus);//任务完成信号
private:
    //推送API对应的TCP对象，实例化后，用该对象连接对应的IP地址和端口。
    //一旦接收到推送API的数据，就会触发信号：readyRead()，表示有数据可读从而触发receiveTcpReadyRead()解析数据。这一步骤在SCStatus类内部通过信号与槽实现。
    //解析出Jsion数据抛出信号emit sigJsonData，触发函数RecvPushHostJsonData 内的Jsion数据解析函数 parseJsonToVehicleSts
    SCStatusTcp *m_robot_push {Q_NULLPTR};
    SCStatusTcp *m_robot_navigate {Q_NULLPTR};
    SCStatusTcp *m_robot_configure {Q_NULLPTR};
    SCStatusTcp *m_robot_control {Q_NULLPTR};


    VehicleSts m_last_veh_status;
    // VehicleStateMachine m_stateMachine;//AGV状态机对象

};

#endif // SCVEHICLE_H
