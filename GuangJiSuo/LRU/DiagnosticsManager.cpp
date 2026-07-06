#include "DiagnosticsManager.h"

#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QFileInfo>
#include <QMutexLocker>
#include <QSysInfo>
#include <QTextStream>
#include <algorithm>
#include <cstdio>

DiagnosticsManager& DiagnosticsManager::instance()
{
    static DiagnosticsManager manager;
    return manager;
}

DiagnosticsManager::~DiagnosticsManager()
{
    closeRuntimeLog();
}

void DiagnosticsManager::initialize()
{
    if (m_initialized) {
        return;
    }

    const QString appDir = QCoreApplication::applicationDirPath();
    m_sessionId = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
    m_baseDir = QDir(appDir).absoluteFilePath("diagnostics");
    m_sessionDir = QDir(m_baseDir).absoluteFilePath(m_sessionId);

    QDir dir;
    if (!dir.mkpath(m_sessionDir)) {
        std::fprintf(stderr, "Diagnostics disabled: cannot create directory: %s\n",
                     qPrintable(m_sessionDir));
        return;
    }

    m_runtimeLogFile.setFileName(QDir(m_sessionDir).absoluteFilePath("run.log"));
    if (m_runtimeLogFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        m_runtimeLogStream.setDevice(&m_runtimeLogFile);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        m_runtimeLogStream.setCodec("UTF-8");
#endif
        m_runtimeLogReady = true;
    } else {
        std::fprintf(stderr, "Diagnostics warning: cannot open run.log: %s\n",
                     qPrintable(m_runtimeLogFile.errorString()));
    }

    m_initialized = true;
    writeManifest();
    snapshotRuntimeFiles();
    cleanupOldSessions(30);
}

QString DiagnosticsManager::sessionDir() const
{
    return m_sessionDir;
}

void DiagnosticsManager::appendRuntimeLog(const QString &line)
{
    QMutexLocker locker(&m_logMutex);
    if (!m_initialized || m_sessionDir.isEmpty()) {
        return;
    }

    if (!m_runtimeLogReady) {
        return;
    }

    m_runtimeLogStream << line;
    m_runtimeLogStream.flush();
}

void DiagnosticsManager::closeRuntimeLog()
{
    QMutexLocker locker(&m_logMutex);
    if (m_runtimeLogReady) {
        m_runtimeLogStream.flush();
        m_runtimeLogStream.setDevice(nullptr);
        m_runtimeLogFile.close();
        m_runtimeLogReady = false;
    }
}

QString DiagnosticsManager::findExistingFile(const QStringList &relativePaths) const
{
    const QString appDir = QCoreApplication::applicationDirPath();
    const QString currentDir = QDir::currentPath();

    for (const QString &relativePath : relativePaths) {
        const QStringList candidates = {
            QDir(appDir).absoluteFilePath(relativePath),
            QDir(currentDir).absoluteFilePath(relativePath),
            relativePath
        };

        for (const QString &candidate : candidates) {
            QFileInfo info(candidate);
            if (info.exists() && info.isFile()) {
                return info.absoluteFilePath();
            }
        }
    }

    return QString();
}

void DiagnosticsManager::writeManifest() const
{
    QFile file(QDir(m_sessionDir).absoluteFilePath("manifest.txt"));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    out.setCodec("UTF-8");
#endif
    out << "SessionId=" << m_sessionId << "\n";
    out << "AppStartTime=" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << "\n";
    out << "AppVersion=unknown\n";
    out << "AppDir=" << QCoreApplication::applicationDirPath() << "\n";
    out << "CurrentDir=" << QDir::currentPath() << "\n";
    out << "QtVersion=" << QT_VERSION_STR << "\n";
    out << "BuildCpuArchitecture=" << QSysInfo::buildCpuArchitecture() << "\n";
    out << "CurrentCpuArchitecture=" << QSysInfo::currentCpuArchitecture() << "\n";
    out << "ProductType=" << QSysInfo::productType() << "\n";
    out << "ProductVersion=" << QSysInfo::productVersion() << "\n";
    out << "ComputerName=" << QString::fromLocal8Bit(qgetenv("COMPUTERNAME")) << "\n";
    out << "UserName=" << QString::fromLocal8Bit(qgetenv("USERNAME")) << "\n";
}

void DiagnosticsManager::snapshotRuntimeFiles() const
{
    const QString configDir = QDir(m_sessionDir).absoluteFilePath("config");
    QDir().mkpath(configDir);

    copyIfExists(findExistingFile({"param.ini"}), QDir(configDir).absoluteFilePath("param.ini"));
    copyIfExists(findExistingFile({"lru_params.json"}), QDir(configDir).absoluteFilePath("lru_params.json"));
    copyIfExists(findExistingFile({"crash_log.txt"}), QDir(m_sessionDir).absoluteFilePath("crash_log_snapshot.txt"));

    const QString appResourceDir = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("vision/resource");
    const QString cwdResourceDir = QDir(QDir::currentPath()).absoluteFilePath("vision/resource");
    const QString destinationCalibrationDir = QDir(configDir).absoluteFilePath("camera_calibrations");

    if (QDir(appResourceDir).exists()) {
        copyCameraCalibrationFiles(appResourceDir, destinationCalibrationDir);
    } else if (QDir(cwdResourceDir).exists()) {
        copyCameraCalibrationFiles(cwdResourceDir, destinationCalibrationDir);
    }
}

void DiagnosticsManager::copyIfExists(const QString &sourcePath, const QString &destinationPath) const
{
    if (sourcePath.isEmpty()) {
        return;
    }

    QFileInfo sourceInfo(sourcePath);
    if (!sourceInfo.exists() || !sourceInfo.isFile()) {
        return;
    }

    QDir().mkpath(QFileInfo(destinationPath).absolutePath());
    if (QFile::exists(destinationPath)) {
        QFile::remove(destinationPath);
    }
    QFile::copy(sourceInfo.absoluteFilePath(), destinationPath);
}

void DiagnosticsManager::copyCameraCalibrationFiles(const QString &sourceResourceDir, const QString &destinationDir) const
{
    QDir sourceDir(sourceResourceDir);
    if (!sourceDir.exists()) {
        return;
    }

    QDirIterator it(sourceResourceDir,
                    QStringList() << "camera_calibration_*.json",
                    QDir::Files,
                    QDirIterator::Subdirectories);

    while (it.hasNext()) {
        const QString sourcePath = it.next();
        const QString relativePath = sourceDir.relativeFilePath(sourcePath);
        copyIfExists(sourcePath, QDir(destinationDir).absoluteFilePath(relativePath));
    }
}

void DiagnosticsManager::cleanupOldSessions(int keepCount) const
{
    QDir base(m_baseDir);
    if (!base.exists()) {
        return;
    }

    QFileInfoList entries = base.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot,
                                               QDir::Name | QDir::Reversed);
    for (int i = keepCount; i < entries.size(); ++i) {
        QDir oldSession(entries[i].absoluteFilePath());
        oldSession.removeRecursively();
    }
}
