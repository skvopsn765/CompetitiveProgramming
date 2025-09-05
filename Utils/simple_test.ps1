# 簡單的 PowerShell 測試腳本
param([string]$ProblemPath = "Problems\UVA_100")

Write-Host "=== 競程測試工具 (PowerShell 版) ===" -ForegroundColor Green

# 檢查題目資料夾是否存在
if (-not (Test-Path $ProblemPath)) {
    Write-Host "錯誤: 找不到題目資料夾 $ProblemPath" -ForegroundColor Red
    exit 1
}

Write-Host "正在測試題目: $ProblemPath" -ForegroundColor Yellow

# 檢查是否有 g++ 編譯器
$gppExists = $false
try {
    $null = Get-Command g++ -ErrorAction Stop
    $gppExists = $true
    Write-Host "找到 g++ 編譯器" -ForegroundColor Green
}
catch {
    Write-Host "未找到 g++ 編譯器" -ForegroundColor Yellow
    Write-Host "建議使用 Visual Studio 來編譯和測試程式" -ForegroundColor Cyan
    Write-Host "請參考 VISUAL_STUDIO_GUIDE.md 了解詳細步驟" -ForegroundColor Cyan
}

if ($gppExists) {
    # 編譯程式
    $sourceFile = Join-Path $ProblemPath "solution.cpp"
    $execFile = Join-Path $ProblemPath "solution.exe"

    Write-Host "正在編譯: $sourceFile" -ForegroundColor Yellow
    
    $compileResult = Start-Process -FilePath "g++" -ArgumentList "-DLOCAL", "-std=c++14", "-O2", "-o", "`"$execFile`"", "`"$sourceFile`"" -Wait -PassThru -NoNewWindow
    
    if ($compileResult.ExitCode -eq 0) {
        Write-Host "編譯成功！" -ForegroundColor Green
        
        # 執行測試
        Write-Host "`n開始執行測試..." -ForegroundColor Green
        
        # 複製第一個測試檔案
        $inputFile = Join-Path $ProblemPath "input1.txt"
        $testInputFile = Join-Path $ProblemPath "input.txt"
        
        if (Test-Path $inputFile) {
            Copy-Item $inputFile $testInputFile -Force
            Write-Host "已複製測試輸入檔案" -ForegroundColor Green
            
            # 執行程式
            $execResult = Start-Process -FilePath $execFile -Wait -PassThru -NoNewWindow
            
            if ($execResult.ExitCode -eq 0) {
                Write-Host "程式執行成功！" -ForegroundColor Green
                
                # 顯示輸出
                $outputFile = Join-Path $ProblemPath "output.txt"
                if (Test-Path $outputFile) {
                    Write-Host "`n實際輸出:" -ForegroundColor Cyan
                    Get-Content $outputFile | ForEach-Object { Write-Host "  $_" }
                    
                    # 顯示預期輸出
                    $expectedFile = Join-Path $ProblemPath "expected1.txt"
                    if (Test-Path $expectedFile) {
                        Write-Host "`n預期輸出:" -ForegroundColor Cyan
                        Get-Content $expectedFile | ForEach-Object { Write-Host "  $_" }
                        
                        # 簡單比較
                        $actualOutput = Get-Content $outputFile | ForEach-Object { $_.TrimEnd() }
                        $expectedOutput = Get-Content $expectedFile | ForEach-Object { $_.TrimEnd() }
                        
                        $comparison = Compare-Object $actualOutput $expectedOutput
                        if ($comparison -eq $null) {
                            Write-Host "`n✓ 測試通過！輸出正確" -ForegroundColor Green
                            Write-Host "🎉 可以提交到 Online Judge 了！" -ForegroundColor Green
                        } else {
                            Write-Host "`n✗ 測試失敗！輸出不符合預期" -ForegroundColor Red
                        }
                    }
                } else {
                    Write-Host "找不到輸出檔案 output.txt" -ForegroundColor Red
                }
            } else {
                Write-Host "程式執行失敗！" -ForegroundColor Red
            }
        } else {
            Write-Host "找不到測試輸入檔案 input1.txt" -ForegroundColor Red
        }
    } else {
        Write-Host "編譯失敗！請檢查程式碼語法" -ForegroundColor Red
    }
} else {
    Write-Host "`n建議的使用步驟:" -ForegroundColor Yellow
    Write-Host "1. 開啟 Visual Studio" -ForegroundColor White
    Write-Host "2. 開啟 CompetitiveProgramming.sln" -ForegroundColor White
    Write-Host "3. 設定 Problems\UVA_100\solution.cpp 為啟動項目" -ForegroundColor White
    Write-Host "4. 按 F5 執行程式" -ForegroundColor White
    Write-Host "5. 檢查 output.txt 檔案" -ForegroundColor White
}

Write-Host "`n按任意鍵繼續..." -ForegroundColor Gray
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
