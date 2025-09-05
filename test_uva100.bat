@echo off
echo === 測試 UVA 100 題目 ===

REM 檢查檔案是否存在
if not exist "Problems\UVA_100\solution.cpp" (
    echo 錯誤: 找不到 Problems\UVA_100\solution.cpp
    pause
    exit /b 1
)

echo 正在檢查編譯器...

REM 檢查是否有 g++
g++ --version >nul 2>&1
if %errorlevel% equ 0 (
    echo 找到 g++ 編譯器，正在編譯...
    
    REM 編譯程式
    g++ -DLOCAL -std=c++14 -O2 -o "Problems\UVA_100\solution.exe" "Problems\UVA_100\solution.cpp"
    
    if %errorlevel% equ 0 (
        echo 編譯成功！
        
        REM 複製測試輸入
        copy "Problems\UVA_100\input1.txt" "Problems\UVA_100\input.txt" >nul
        echo 已準備測試資料
        
        REM 執行程式
        cd "Problems\UVA_100"
        solution.exe
        cd "..\..\"
        
        echo.
        echo === 實際輸出 ===
        type "Problems\UVA_100\output.txt"
        
        echo.
        echo === 預期輸出 ===
        type "Problems\UVA_100\expected1.txt"
        
        echo.
        echo 請比較上面兩個輸出是否相同
        echo 如果相同，表示程式正確！
        
    ) else (
        echo 編譯失敗！
    )
) else (
    echo 未找到 g++ 編譯器
    echo.
    echo 請使用以下方法之一：
    echo 1. 安裝 MinGW-w64 ^(推薦^)
    echo 2. 使用 Visual Studio:
    echo    - 開啟 CompetitiveProgramming.sln
    echo    - 設定 Problems\UVA_100\solution.cpp 為啟動項目
    echo    - 按 F5 執行
)

echo.
pause
