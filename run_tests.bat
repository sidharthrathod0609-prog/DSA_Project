@echo off
setlocal
set PATH=C:\MinGW\bin;%PATH%
if not exist bin\test_dsa.exe (
    echo Executable not found. Compiling first...
    call build.bat
)
bin\test_dsa.exe
endlocal
