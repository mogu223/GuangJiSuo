@echo off
setlocal

set "VS_VCVARS=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
set "QTDIR=E:\Qt\5.15.2\msvc2019"
set "QTCREATOR=E:\Qt\Tools\QtCreator\bin\qtcreator.exe"

if not exist "%VS_VCVARS%" (
    echo Visual Studio vcvars64.bat not found: %VS_VCVARS%
    exit /b 1
)

if not exist "%QTDIR%\bin\qmake.exe" (
    echo Qt qmake not found: %QTDIR%\bin\qmake.exe
    exit /b 1
)

if not exist "%QTCREATOR%" (
    echo Qt Creator not found: %QTCREATOR%
    exit /b 1
)

call "%VS_VCVARS%" || exit /b 1

set "PATH=%QTDIR%\bin;E:\Qt\Tools\QtCreator\bin\jom;%PATH%"
set "QMAKESPEC=win32-msvc"

start "" "%QTCREATOR%" "%~dp05DOFGantryArm.pro"
