#include "agvmonitor.h"
#include "ui_agvmonitor.h"

AGVMonitor::AGVMonitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AGVMonitor)
{
    ui->setupUi(this);
}

AGVMonitor::~AGVMonitor()
{
    delete ui;
}


void AGVMonitor::UpdateVehStatus(VehicleSts veh_sts)
{
    ui->lineEdit_batt_level->setText(QString::number(veh_sts.battery_level));
    ui->lineEdit_agv_blocked->setText(QString::number(veh_sts.blocked));
    ui->lineEdit_block_reason->setText(BlockReason2Qstr(veh_sts.block_reason));
    ui->lineEdit_taskStatus->setText(TaskStatus2Qstr(veh_sts.task_status));
    ui->lineEdit_emergency->setText(QString::number(veh_sts.emergency));
    ui->lineEdit_soft_emc->setText(QString::number(veh_sts.soft_emc));
    ui->lineEdit_current_station->setText(veh_sts.current_station);
    ui->lineEdit_brake->setText(QString::number(veh_sts.brake));
    ui->lineEdit_task_type->setText(QString::number(veh_sts.task_type));
    ui->lineEdit_target_dist->setText(QString::number(veh_sts.target_dist));
    ui->lineEdit_driver_emc->setText(QString::number(veh_sts.driver_emc));
    ui->lineEdit_electric->setText(QString::number(veh_sts.electric));
    ui->lineEdit_loadmap_status->setText(LoadmapStatus2Qstr(veh_sts.loadmap_status));
    ui->lineEdit_reloc_status->setText(RelocStatus2Qstr(veh_sts.reloc_status));

    for (auto var : veh_sts.finished_path)
    {
        ui->textEdit_Info->append("Finished path:" + var);
    }
    for (auto var : veh_sts.unfinished_path)
    {
        ui->textEdit_Info->append("Unfinished path:" + var);
    }

    for (auto error : veh_sts.errors)
    {
        ui->textEdit_Info->append(QString::number(error.code) + ":" + error.desc);
    }
}


void AGVMonitor::UpdateDistanceData(const QVariantMap &data)
{
    foreach(const QString &key, data.keys()) {
        float value = data[key].toFloat();
        if (key == "distance0") {
            ui->Distance0->setText(QString::number(value, 'f', 1));
        } else if (key == "distance1") {
            ui->Distance1->setText(QString::number(value, 'f', 1));
        } else if (key == "distance2") {
            ui->Distance2->setText(QString::number(value, 'f', 1));
        } else if (key == "distance3") {
            ui->Distance3->setText(QString::number(value, 'f', 1));
        }
    }
}
