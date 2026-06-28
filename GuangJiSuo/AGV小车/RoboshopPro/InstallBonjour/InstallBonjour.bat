@echo off
pushd .
cd /d "%~dp0"

if not "%PROCESSOR_ARCHITECTURE%" == "x86" goto LBL_64BIT_OS
if not defined PROCESSOR_ARCHITEW6432 goto LBL_32BIT_OS
if "%PROCESSOR_ARCHITEW6432%" == "x86" goto LBL_32BIT_OS
goto LBL_64BIT_OS


:LBL_64BIT_OS
Bonjour64.msi /passive
goto LBL_END

:LBL_32BIT_OS
Bonjour.msi /passive
goto LBL_END


:LBL_END
popd
