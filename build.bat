@echo off
setlocal
echo ===================================================
echo   Compiling Bank Management System (C++ / DSA)
echo ===================================================

REM Ensure MinGW bin is in path if installed
set PATH=C:\MinGW\bin;%PATH%

if not exist bin mkdir bin

echo [1/3] Compiling BankManagementSystem.exe ...
g++ -std=c++14 -static -static-libgcc -static-libstdc++ -I include src\main.cpp src\DBClient.cpp src\BankRepository.cpp -o bin\BankManagementSystem.exe
if %ERRORLEVEL% neq 0 (
    echo [ERROR] Failed to compile BankManagementSystem.exe
    exit /b 1
)

echo [2/3] Compiling test_dsa.exe ...
g++ -std=c++14 -static -static-libgcc -static-libstdc++ -I include tests\test_dsa.cpp src\DBClient.cpp src\BankRepository.cpp -o bin\test_dsa.exe
if %ERRORLEVEL% neq 0 (
    echo [ERROR] Failed to compile test_dsa.exe
    exit /b 1
)

echo [3/3] Compiling test_mongo.exe ...
g++ -std=c++14 -static -static-libgcc -static-libstdc++ -I include tests\test_mongo_connection.cpp src\DBClient.cpp -o bin\test_mongo.exe
if %ERRORLEVEL% neq 0 (
    echo [ERROR] Failed to compile test_mongo.exe
    exit /b 1
)

echo.
echo ===================================================
echo   BUILD SUCCESSFUL! All executables are in bin\
echo   - bin\BankManagementSystem.exe
echo   - bin\test_dsa.exe
echo   - bin\test_mongo.exe
echo ===================================================
endlocal
