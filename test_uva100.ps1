# 測試 UVA 100 題目的簡單腳本

Write-Host "=== 測試 UVA 100 題目 ===" -ForegroundColor Green

# 檢查檔案是否存在
if (-not (Test-Path "Problems\UVA_100\solution.cpp")) {
    Write-Host "錯誤: 找不到 Problems\UVA_100\solution.cpp" -ForegroundColor Red
    exit 1
}

# 嘗試使用 g++ 編譯
Write-Host "正在檢查編譯器..." -ForegroundColor Yellow

$hasGpp = $true
try {
    g++ --version | Out-Null
} catch {
    $hasGpp = $false
}

if ($hasGpp) {
    Write-Host "找到 g++ 編譯器，正在編譯..." -ForegroundColor Green
    
    # 編譯
    g++ -DLOCAL -std=c++14 -O2 -o "Problems\UVA_100\solution.exe" "Problems\UVA_100\solution.cpp"
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "編譯成功！" -ForegroundColor Green
        
        # 複製測試輸入
        Copy-Item "Problems\UVA_100\input1.txt" "Problems\UVA_100\input.txt" -Force
        Write-Host "已準備測試資料" -ForegroundColor Green
        
        # 執行程式
        Set-Location "Problems\UVA_100"
        .\solution.exe
        Set-Location "..\..\"
        
        # 顯示結果
        Write-Host "`n=== 實際輸出 ===" -ForegroundColor Cyan
        Get-Content "Problems\UVA_100\output.txt"
        
        Write-Host "`n=== 預期輸出 ===" -ForegroundColor Cyan
        Get-Content "Problems\UVA_100\expected1.txt"
        
        Write-Host "`n請比較上面兩個輸出是否相同" -ForegroundColor Yellow
        Write-Host "如果相同，表示程式正確！" -ForegroundColor Green
        
    } else {
        Write-Host "編譯失敗！" -ForegroundColor Red
    }
} else {
    Write-Host "未找到 g++ 編譯器" -ForegroundColor Yellow
    Write-Host "請使用以下方法之一：" -ForegroundColor Cyan
    Write-Host "1. 安裝 MinGW-w64 (推薦)" -ForegroundColor White
    Write-Host "2. 使用 Visual Studio:" -ForegroundColor White
    Write-Host "   - 開啟 CompetitiveProgramming.sln" -ForegroundColor White
    Write-Host "   - 設定 Problems\UVA_100\solution.cpp 為啟動項目" -ForegroundColor White
    Write-Host "   - 按 F5 執行" -ForegroundColor White
}

Write-Host "`n按 Enter 鍵結束..."
Read-Host
