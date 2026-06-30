#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "cameraworker.h"
#include <cstdio>

// 日志处理函数
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{

    // 过滤"Unsupported media type" 警告
    if (msg.contains("Unsupported media type")) {
        return;
    }

    Q_UNUSED(context);
    QByteArray localMsg = msg.toLocal8Bit(); // 处理本地编码

    switch (type) {
    case QtDebugMsg:
        fprintf(stdout, "[Debug] %s\n", localMsg.constData());
        break;
    case QtInfoMsg:
        fprintf(stdout, "[Info] %s\n", localMsg.constData());
        break;
    case QtWarningMsg:
        fprintf(stderr, "[Warning] %s\n", localMsg.constData());
        break;
    case QtCriticalMsg:
        fprintf(stderr, "[Critical] %s\n", localMsg.constData());
        break;
    case QtFatalMsg:
        fprintf(stderr, "[Fatal] %s\n", localMsg.constData());
        abort();
    }

    fflush(stdout); // 刷新缓冲区
    fflush(stderr);
}


int main(int argc, char *argv[])
{
    #ifdef Q_OS_WIN
    qputenv("QT_MEDIA_BACKEND", "mediafoundation");
    #endif

    // 安装日志处理器
    qInstallMessageHandler(customMessageHandler);

    QCoreApplication a(argc, argv);

    // 解析相机索引 和 共享内存Key
    QCommandLineParser parser;
    parser.addPositionalArgument("cameraIndex", "相机索引");
    parser.addPositionalArgument("shmKey", "共享内存Key");
    parser.process(a);

    QStringList args = parser.positionalArguments();
    if (args.size() != 2) {
        qCritical() << "使用方式: camera_worker <cameraIndex> <shmKey>";
        return 1;
    }

    bool ok;
    int cameraIndex = args[0].toInt(&ok);
    if (!ok) {
        qCritical() << "无效的相机索引！";
        return 1;
    }
    QString shmKey = args[1];

    // 启动相机采集
    CameraWorker worker(cameraIndex, shmKey);
    return a.exec();
}
