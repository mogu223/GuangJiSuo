#include "cameraworker.h"
#include <QDebug>

CameraWorker::CameraWorker(int cameraIndex, const QString& shmKey, QObject *parent)
    : QObject(parent)
    , m_cameraIndex(cameraIndex)
    , m_shmManager(new SharedMemoryManager(shmKey))
    , m_captureTimer(new QTimer(this))
{
    // 初始化相机
    m_camera = new UVC_Camera(this);
    bool opened = m_camera->openCamera(m_cameraIndex);
    if (!opened) {
        qCritical() << "相机" << cameraIndex << "打开失败！";
        return;
    }

    // 绑定帧捕获信号
    connect(m_camera, &UVC_Camera::frameCaptured, this, &CameraWorker::onFrameCaptured);

    // 定时采集
    m_captureTimer->setInterval(33);
    connect(m_captureTimer, &QTimer::timeout, this, &CameraWorker::captureFramePeriodically);
    m_captureTimer->start();
}

CameraWorker::~CameraWorker()
{
    m_captureTimer->stop();
    if (m_camera) {
        m_camera->closeCamera();
        delete m_camera;
    }
    delete m_shmManager;
}

void CameraWorker::onFrameCaptured(const QImage& frame)
{
    // 采集帧写入共享内存
    bool success = m_shmManager->writeImage(frame);
    if (!success) {
        qWarning() << "相机" << m_cameraIndex << "共享内存写入失败！";
    }
}

void CameraWorker::captureFramePeriodically()
{
    if (m_camera->isCameraOpened()) {
        m_camera->captureFrame();
    }
}
