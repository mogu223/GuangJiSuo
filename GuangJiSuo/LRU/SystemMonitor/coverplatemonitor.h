#ifndef COVERPLATEMONITOR_H
#define COVERPLATEMONITOR_H

#include <QMainWindow>

namespace Ui {
class CoverPlateMonitor;
}

class CoverPlateMonitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoverPlateMonitor(QWidget *parent = nullptr);
    ~CoverPlateMonitor();

private:
    Ui::CoverPlateMonitor *ui;
};

#endif // COVERPLATEMONITOR_H
