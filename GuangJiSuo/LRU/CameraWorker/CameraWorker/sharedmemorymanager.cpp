#include "sharedmemorymanager.h"
#include <QDebug>

SharedMemoryManager::SharedMemoryManager(const QString& key)
    : m_key(key)
{
    m_sharedMemory.setKey(key);
}


SharedMemoryManager::~SharedMemoryManager()
{
    release();
}

bool SharedMemoryManager::writeImage(const QImage& image)
{
    if (image.isNull()) {
        qWarning() << "写入的图像为空，跳过共享内存写入";
        return false;
    }

    // 图像转字节数组
    QBuffer buffer;
    buffer.open(QBuffer::WriteOnly);
    if (!image.save(&buffer, "PNG", 50)) {
        qWarning() << "图像保存为PNG失败";
        return false;
    }
    QByteArray byteArray = buffer.data();

    if (byteArray.isEmpty()) {
        qWarning() << "图像转换后的字节数组为空";
        return false;
    }

    // 创建固定大小共享内存
    if (m_sharedMemory.size() == 0) {
        int size = 10 * 1024 * 1024;
        if (!m_sharedMemory.create(size)) {
            qInfo() << "共享内存创建失败，Key:" << m_key << "错误:" << m_sharedMemory.errorString();
            return false;
        }
    }

    // 确保附着
    if (!m_sharedMemory.isAttached()) {
        if (!m_sharedMemory.attach()) {
            qCritical() << "共享内存附着失败，Key:" << m_key << "错误:" << m_sharedMemory.errorString();
            return false;
        }
    }

    // 加锁写入数据
    m_sharedMemory.lock();
    char* to = static_cast<char*>(m_sharedMemory.data());
    const char* from = byteArray.constData();
    memcpy(to, from, byteArray.size());
    m_sharedMemory.unlock();

    return true;
}

QImage SharedMemoryManager::readImage()
{
    if (!m_sharedMemory.isAttached()) {
        if (!m_sharedMemory.attach()) return QImage();
    }

    // 加锁读取数据
    m_sharedMemory.lock();
    QByteArray byteArray(static_cast<char*>(m_sharedMemory.data()), m_sharedMemory.size());
    m_sharedMemory.unlock();

    // 反转换为图像
    QImage image;
    image.loadFromData(byteArray, "PNG");
    return image;
}

void SharedMemoryManager::release()
{
    if (m_sharedMemory.isAttached()) {
        m_sharedMemory.detach();
    }
}
