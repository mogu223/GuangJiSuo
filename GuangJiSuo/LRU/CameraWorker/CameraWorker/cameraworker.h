#ifndef CAMERA_WORKER_H
#define CAMERA_WORKER_H

#include <QObject>
#include <QTimer>
#include "uvc_camera.h"
#include "sharedmemorymanager.h"

class CameraWorker : public QObject
{
    Q_OBJECT
public:
    explicit CameraWorker(int cameraIndex, const QString& shmKey, QObject *parent = nullptr);
    ~CameraWorker() override;

private slots:
    void onFrameCaptured(const QImage& frame);
    void captureFramePeriodically(); // 定时采集帧

private:
    UVC_Camera* m_camera;
    int m_cameraIndex;
    SharedMemoryManager* m_shmManager;
    QTimer* m_captureTimer; // 30fps定时采集
};

#endif // CAMERA_WORKER_H
