#ifndef LIFTMONITOR_H
#define LIFTMONITOR_H

#include <QMainWindow>
#include "TCPSensor.h"
#include "Lift.h"

namespace Ui {
class LiftMonitor;
}

// 六自由度平台信息结构体
struct SixDofPlatformData {
    float x;
    float y;
    float z;
    float rx;
    float ry;
    float rz;
    int motion_mode;
    bool servo_enabled;
    bool target_reached;
    QString alarmText;
    bool hasClientConnected;
};

// 视觉信息结构体
struct DetectedDisplayData {
    float angle;
    float rho1;
    float rho2;
};

class LiftMonitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit LiftMonitor(ZMotionControl* zm,QWidget *parent = nullptr);
    bool IsCollsion = false;
    QTimer* IsCollsionTimer;
    ~LiftMonitor();

public slots:
    void onMotorStatusUpdated();
    void updateSixAxisSensorInfo(float fx, float fy, float fz, float mx, float my, float mz);
    void updateSixDofPlatformUI(const SixDofPlatformData& data);
    void updateDetectedDisplayUI(const DetectedDisplayData& data);
    void UpdateCollsionUI();


signals:

private:
    Ui::LiftMonitor *ui;
    ZMotionControl* m_zm;
};

#endif // LIFTMONITOR_H
