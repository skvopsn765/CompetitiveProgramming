@echo off
REM 批次測試腳本 - 適用於 Windows

if "%1"=="" (
    echo 使用方法: build_and_test.bat ^<題目資料夾^>
    echo 範例: build_and_test.bat Problems\UVA_100
    exit /b 1
)

set PROBLEM_PATH=%1

if not exist "%PROBLEM_PATH%" (
    echo 錯誤: 找不到題目資料夾 %PROBLEM_PATH%
    exit /b 1
)

echo 正在編譯測試執行器...
g++ -std=c++17 -O2 -o Utils\test_runner.exe Utils\test_runner.cpp

if %ERRORLEVEL% neq 0 (
    echo 測試執行器編譯失敗！
    exit /b 1
)

echo 執行測試...
Utils\test_runner.exe "%PROBLEM_PATH%"

pause
