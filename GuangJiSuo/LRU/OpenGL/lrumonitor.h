#ifndef LRUMONITOR_H
#define LRUMONITOR_H

#include <QMainWindow>
#include "LRU.h"

namespace Ui {
class lrumonitor;
}

class lrumonitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit lrumonitor(QWidget *parent = nullptr);
    ~lrumonitor();

    // 视觉数据接口
    float m_GapWidth;
    float m_AxisPos;
    float m_GapWidth1;
    float m_GapAngle;

private:
    Ui::lrumonitor *ui;

    //光学模块类
    LRU *m_lru;
    QOpenGLWidget* m_glWidget;
    lrumonitor *monitor;


private slots:
    //LRU数字孪生模块
    void on_btn_LoadLRU_clicked();

    void on_btn_MonitorStart_clicked();
};

#endif // LRUMONITOR_H
