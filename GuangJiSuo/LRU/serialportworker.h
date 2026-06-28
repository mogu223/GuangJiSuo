#ifndef SERIALPORTWORKER_H
#define SERIALPORTWORKER_H

#pragma once
#include <QObject>
#include <QSerialPort>
#include <QMutex>

class SerialPortWorker : public QObject {
    Q_OBJECT
public:
    explicit SerialPortWorker(QObject *parent = nullptr);
    void setPort(QSerialPort *port);
    void stop();

public slots:
    void processData();

signals:
    void dataReceived(const QByteArray &data);
    void sensorDataParsed(int station, float value);

private:
    QSerialPort *m_serialPort;
    QByteArray m_buffer;
    QMutex m_mutex;
    bool m_running = true;
};

#endif // SERIALPORTWORKER_H
