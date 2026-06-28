#include "coverplatemonitor.h"
#include "ui_coverplatemonitor.h"

CoverPlateMonitor::CoverPlateMonitor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CoverPlateMonitor)
{
    ui->setupUi(this);
}

CoverPlateMonitor::~CoverPlateMonitor()
{
    delete ui;
}
