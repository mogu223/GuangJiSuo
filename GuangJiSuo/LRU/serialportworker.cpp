#include "serialportworker.h"

SerialPortWorker::SerialPortWorker(QObject *parent) : QObject(parent) {}

void SerialPortWorker::setPort(QSerialPort *port) {
    m_serialPort = port;
}

void SerialPortWorker::stop() {
    m_running = false;
}

void SerialPortWorker::processData() {
    while (m_running) {
        if (m_serialPort && m_serialPort->isOpen()) {
            QMutexLocker locker(&m_mutex);
            QByteArray newData = m_serialPort->readAll();
            if (!newData.isEmpty()) {
                m_buffer.append(newData);
                // 触发数据处理
                emit dataReceived(m_buffer);
            }
        }
        QThread::msleep(10); // 适当降低CPU占用
    }
}
