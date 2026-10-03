@echo off
setlocal
set PATH=C:\MinGW\bin;%PATH%
if not exist bin\BankManagementSystem.exe (
    echo Executable not found. Compiling first...
    call build.bat
)
bin\BankManagementSystem.exe
endlocal
