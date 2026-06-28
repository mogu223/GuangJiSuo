#include "levelmonitor.h"
#include "ui_levelmonitor.h"
#include "zmotioncontrol.h"

LevelMonitor::LevelMonitor(ZMotionControl* zm,QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LevelMonitor),m_zm(zm)
{
    ui->setupUi(this);
}

LevelMonitor::~LevelMonitor()
{
    delete ui;
}

//同步传感器数据
void LevelMonitor::UpdateForceData(const QVariantMap &data)
{
    foreach(const QString &key, data.keys()) {
        float value = data[key].toFloat();
        if (key == "sensor0") {
            ui->sensor0->setText(QString::number(value, 'f', 4));
        } else if (key == "sensor1") {
            ui->sensor1->setText(QString::number(value, 'f', 4));
        } else if (key == "sensor2") {
            ui->sensor2->setText(QString::number(value, 'f', 4));
        } else if (key == "sensor3") {
            ui->sensor3->setText(QString::number(value, 'f', 4));
        }
    }
}

void LevelMonitor::UpdateAngleData(const QVariantMap &data)
{
    if (data.contains("angleX")) {
        ui->AngleX->setText(QString::number(data["angleX"].toFloat(), 'f', 4));
    }
    if (data.contains("angleY")) {
        ui->AngleY->setText(QString::number(data["angleY"].toFloat(), 'f', 4));
    }
}

//同步电流数据
void LevelMonitor::CurrentUpdate(float current0, float current1, float current2, float current3)
{
    ui->Current0->setText(QString::number(current0, 'f', 2));
    ui->Current1->setText(QString::number(current1, 'f', 2));
    ui->Current2->setText(QString::number(current2, 'f', 2));
    ui->Current3->setText(QString::number(current3, 'f', 2));
}

//同步电机状态
void LevelMonitor::onMotorStatusUpdated()
{
    QLabel* Status[] = {ui->lblAxisStatus0 ,ui->lblAxisStatus1 ,ui->lblAxisStatus2 ,ui->lblAxisStatus3};
    QLabel* Position[] = {ui->lblPosi0 ,ui->lblPosi1 ,ui->lblPosi2 ,ui->lblPosi3};
    QLabel* Units[] = {ui->lblAxisUnits0 ,ui->lblAxisUnits1,ui->lblAxisUnits2 ,ui->lblAxisUnits3};
    QLabel* Speed[] = {ui->lblAxisSpeed0 ,ui->lblAxisSpeed1, ui->lblAxisSpeed2 ,ui->lblAxisSpeed3};
    QLabel* Accel[] = {ui->lblAxisAccel0, ui->lblAxisAccel1, ui->lblAxisAccel2, ui->lblAxisAccel3};
    QLabel* Decel[] = {ui->lblAxisDecel0, ui->lblAxisDecel1, ui->lblAxisDecel2, ui->lblAxisDecel3};
    QLabel* FsLimit[] = {ui->lblFsLimit0, ui->lblFsLimit1, ui->lblFsLimit2,ui->lblFsLimit3};
    QLabel* BsLimit[] = {ui->lblBsLimit0, ui->lblBsLimit1, ui->lblBsLimit2,ui->lblBsLimit3};
    QLabel* Type[] = {ui->lblAxisType0, ui->lblAxisType1, ui->lblAxisType2, ui->lblAxisType3};
    for(int i = 0; i < 4; ++i)
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

//同步标志位
void LevelMonitor::onFeetToGround(int index)
{
    QLabel* label[] = {ui->lbl_Symbol0,ui->lbl_Symbol1,ui->lbl_Symbol2,ui->lbl_Symbol3};
    label[index]->setStyleSheet("background-color: red;");
}

void LevelMonitor::onBalance()
{
    ui->lbl_SymbolAll->setStyleSheet("background-color: red;");
}


void LevelMonitor::onRestart()
{
    QLabel* label[] = {ui->lbl_Symbol0,ui->lbl_Symbol1,ui->lbl_Symbol2,ui->lbl_Symbol3};
    for(int i=0;i<4;++i)
    {
        label[i]->setStyleSheet("background-color: green;");
    }
    ui->lbl_SymbolAll->setStyleSheet("background-color: green;");
}
