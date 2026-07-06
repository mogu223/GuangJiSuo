#include "CrashHandler.h"
#include "DiagnosticsManager.h"
#include "qcoreapplication.h"
#include <QDir>
#include <QFileInfo>

namespace {

QString buildCrashLogText(EXCEPTION_POINTERS* exceptionInfo)
{
    QString text;
    QTextStream out(&text);
    out << "\n=== Crash Occurred at " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ===\n";
    out << QString("Exception Code: 0x%1\n")
               .arg(exceptionInfo->ExceptionRecord->ExceptionCode, 0, 16);
    out << QString("Exception Address: 0x%1\n")
               .arg(reinterpret_cast<quintptr>(exceptionInfo->ExceptionRecord->ExceptionAddress), 0, 16);
    out << "Call stack not available (DbgHelp not used).\n";
    out << "============================================================\n";
    return text;
}

void appendTextFile(const QString &path, const QString &text)
{
    if (path.isEmpty()) {
        return;
    }

    QDir().mkpath(QFileInfo(path).absolutePath());
    QFile file(path);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        out.setCodec("UTF-8");
#endif
        out << text;
        out.flush();
        file.close();
    }
}

}

void CrashHandler::install() {
    SetUnhandledExceptionFilter(CrashHandler::exceptionFilter);
}

LONG WINAPI CrashHandler::exceptionFilter(EXCEPTION_POINTERS* exceptionInfo) {
    const QString crashText = buildCrashLogText(exceptionInfo);
    appendTextFile("crash_log.txt", crashText);

    const QString diagnosticsDir = DiagnosticsManager::instance().sessionDir();
    if (!diagnosticsDir.isEmpty()) {
        appendTextFile(QDir(diagnosticsDir).absoluteFilePath("crash_log.txt"), crashText);
    }

    // 重启应用
//    restartApplication();

    return EXCEPTION_EXECUTE_HANDLER;
}

void CrashHandler::restartApplication() {
    TCHAR moduleName[MAX_PATH];
    GetModuleFileName(NULL, moduleName, MAX_PATH);

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    if (CreateProcess(
            moduleName,
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi)) {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}
void CrashHandler::restartApplication2() {
    QString appPath = QCoreApplication::applicationFilePath().replace("/", "\\");
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;

    if (CreateProcessW((LPCWSTR)appPath.utf16(), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}
