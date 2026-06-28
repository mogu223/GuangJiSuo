#include "liftmonitor.h"
#include "ui_liftmonitor.h"


LiftMonitor::LiftMonitor(ZMotionControl* zm,QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LiftMonitor), m_zm(zm)
{
    ui->setupUi(this);
    IsCollsionTimer = new QTimer(this);

}

LiftMonitor::~LiftMonitor()
{
    delete ui;
}

void LiftMonitor::updateSixAxisSensorInfo(float fx, float fy, float fz, float mx, float my, float mz)
{
    ui->lbl_FX->setText(QString::number(fx, 'f', 3));
    ui->lbl_FY->setText(QString::number(fy, 'f', 3));
    ui->lbl_FZ->setText(QString::number(fz, 'f', 3));
    ui->lbl_MX->setText(QString::number(mx, 'f', 3));
    ui->lbl_MY->setText(QString::number(my, 'f', 3));
    ui->lbl_MZ->setText(QString::number(mz, 'f', 3));
}


//同步电机状态
void LiftMonitor::onMotorStatusUpdated()
{
    QLabel* Status[] = {ui->lblAxisStatus4 ,ui->lblAxisStatus5 };
    QLabel* Position[] = {ui->lblPosi4 ,ui->lblPosi5};
    QLabel* Units[] = {ui->lblAxisUnits4 ,ui->lblAxisUnits5};
    QLabel* Speed[] = {ui->lblAxisSpeed4 ,ui->lblAxisSpeed5};
    QLabel* Accel[] = {ui->lblAxisAccel4, ui->lblAxisAccel5};
    QLabel* Decel[] = {ui->lblAxisDecel4, ui->lblAxisDecel5};
    QLabel* FsLimit[] = {ui->lblFsLimit4, ui->lblFsLimit5};
    QLabel* BsLimit[] = {ui->lblBsLimit4, ui->lblBsLimit5};
    QLabel* Type[] = {ui->lblAxisType4, ui->lblAxisType5};
    for(int i = 0; i < 2; ++i)
    {
        Status[i]->setText(AxisStatusQstr(m_zm->GetAxisStatus(i)));
        Position[i]->setText(QString::number(m_zm->GetAxisDpos(i)));
        Units[i]->setText(QString::number(m_zm->GetAxisUnits(i)));
        Speed[i]->setText(QString::number(m_zm->GetAxisSpeed(i)));
        Accel[i]->setText(QString::number(m_zm->GetAxisAccel(i)));
        Decel[i]->setText(QString::number(m_zm->GetAxisDecel(i)));
        FsLimit[i]->setText(QString::number(m_zm->GetAxisFSLimit(i)));
        BsLimit[i]->setText(QString::number(m_zm->GetAxisRSLimit(i)));
        Type[i]->setText(QString::number(m_zm->GetAxisMType(i)));
    }
}


//同步碰撞标志位
void LiftMonitor::UpdateCollsionUI()
{
    connect(IsCollsionTimer,&QTimer::timeout,this,[=](){

        if (IsCollsion)
        {
            ui->lbl_CrashInfo->setText("检测到碰撞，恢复至安全位置和姿态！");
            QString baseStyle = "border-radius: 25px; border: 2px solid black; background-color: red;";
            ui->lbl_isCrash->setStyleSheet(baseStyle);
        }
        else
        {
            ui->lbl_CrashInfo->setText("当前未检测到碰撞");
            QString baseStyle = "border-radius: 25px; border: 2px solid black; background-color: green;";
            ui->lbl_isCrash->setStyleSheet(baseStyle);
        }

    });

    IsCollsionTimer->start(100);
}

void LiftMonitor::updateSixDofPlatformUI(const SixDofPlatformData& data)
{
    // 更新六自由度平台信息
    ui->lbl_PlatformInfoX->setText(QString::number(data.x));
    ui->lbl_PlatformInfoY->setText(QString::number(data.y));
    ui->lbl_PlatformInfoZ->setText(QString::number(data.z));
    ui->lbl_PlatformInfoRx->setText(QString::number(data.rx));
    ui->lbl_PlatformInfoRy->setText(QString::number(data.ry));
    ui->lbl_PlatformInfoRz->setText(QString::number(data.rz));
    ui->lbl_PlatformStatus->setText(QString::number(data.motion_mode));
    ui->lbl_PlatformEnable->setText(data.servo_enabled ? "True" : "False");
    ui->lbl_PlatformIsTarget->setText(data.target_reached ? "True" : "False");
    ui->lbl_ViewIsConnect->setText(data.hasClientConnected ? "True" : "False");
    ui->lbl_PlatformWarning->setText(data.alarmText);
}

void LiftMonitor::updateDetectedDisplayUI(const DetectedDisplayData& data)
{
    // 更新视觉信息
    ui->lbl_GapAngle->setText(QString::number(data.angle));
    ui->lbl_GapWidth->setText(QString::number(data.rho1));
    ui->lbl_GapWidth1->setText(QString::number(data.rho2));
}
