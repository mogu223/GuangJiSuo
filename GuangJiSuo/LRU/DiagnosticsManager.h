#ifndef DIAGNOSTICSMANAGER_H
#define DIAGNOSTICSMANAGER_H

#include <QFile>
#include <QMutex>
#include <QString>
#include <QStringList>
#include <QTextStream>

class DiagnosticsManager
{
public:
    static DiagnosticsManager& instance();
    ~DiagnosticsManager();

    void initialize();
    QString sessionDir() const;
    void appendRuntimeLog(const QString &line);

private:
    DiagnosticsManager() = default;

    void closeRuntimeLog();
    QString findExistingFile(const QStringList &relativePaths) const;
    void writeManifest() const;
    void snapshotRuntimeFiles() const;
    void copyIfExists(const QString &sourcePath, const QString &destinationPath) const;
    void copyCameraCalibrationFiles(const QString &sourceResourceDir, const QString &destinationDir) const;
    void cleanupOldSessions(int keepCount) const;

    QString m_baseDir;
    QString m_sessionDir;
    QString m_sessionId;
    QFile m_runtimeLogFile;
    QTextStream m_runtimeLogStream;
    QMutex m_logMutex;
    bool m_initialized = false;
    bool m_runtimeLogReady = false;
};

#endif // DIAGNOSTICSMANAGER_H
