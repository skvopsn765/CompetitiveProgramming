# PowerShell 測試腳本
param(
    [Parameter(Mandatory=$true)]
    [string]$ProblemPath
)

Write-Host "=== 競程測試工具 (PowerShell 版) ===" -ForegroundColor Green

# 檢查題目資料夾是否存在
if (-not (Test-Path $ProblemPath)) {
    Write-Host "錯誤: 找不到題目資料夾 $ProblemPath" -ForegroundColor Red
    exit 1
}

Write-Host "正在測試題目: $ProblemPath" -ForegroundColor Yellow

# 檢查是否有 g++ 編譯器
try {
    $null = Get-Command g++ -ErrorAction Stop
    Write-Host "找到 g++ 編譯器" -ForegroundColor Green
} catch {
    Write-Host "警告: 未找到 g++ 編譯器，請確認已安裝 MinGW 或 Visual Studio Build Tools" -ForegroundColor Yellow
    Write-Host "你可以使用 Visual Studio 來編譯和測試程式" -ForegroundColor Yellow
    Write-Host "請參考 VISUAL_STUDIO_GUIDE.md 了解如何在 Visual Studio 中使用" -ForegroundColor Cyan
    exit 1
}

# 編譯程式
$sourceFile = Join-Path $ProblemPath "solution.cpp"
$execFile = Join-Path $ProblemPath "solution.exe"

Write-Host "正在編譯: $sourceFile" -ForegroundColor Yellow
$compileCmd = "g++ -DLOCAL -std=c++14 -O2 -o `"$execFile`" `"$sourceFile`""
Write-Host "編譯指令: $compileCmd" -ForegroundColor Gray

try {
    Invoke-Expression $compileCmd
    if ($LASTEXITCODE -ne 0) {
        throw "編譯失敗"
    }
    Write-Host "編譯成功！" -ForegroundColor Green
} catch {
    Write-Host "編譯失敗！請檢查程式碼語法" -ForegroundColor Red
    exit 1
}

# 執行測試
Write-Host "`n開始執行測試..." -ForegroundColor Green
Write-Host "===================" -ForegroundColor Green

$testCount = 0
$passedCount = 0

# 尋找所有測試檔案
$inputFiles = Get-ChildItem -Path $ProblemPath -Name "input*.txt" | Sort-Object
foreach ($inputFile in $inputFiles) {
    $testNumber = $inputFile -replace "input", "" -replace "\.txt", ""
    $expectedFile = "expected$testNumber.txt"
    $expectedPath = Join-Path $ProblemPath $expectedFile
    
    if (Test-Path $expectedPath) {
        $testCount++
        Write-Host "`n測試案例 $testNumber :" -ForegroundColor Cyan
        
        # 複製輸入檔案
        $inputPath = Join-Path $ProblemPath $inputFile
        $testInputPath = Join-Path $ProblemPath "input.txt"
        Copy-Item $inputPath $testInputPath -Force
        
        # 執行程式
        $startTime = Get-Date
        try {
            & $execFile
            $endTime = Get-Date
            $duration = ($endTime - $startTime).TotalMilliseconds
            
            # 比較輸出
            $outputPath = Join-Path $ProblemPath "output.txt"
            if (Test-Path $outputPath) {
                $actualOutput = Get-Content $outputPath | ForEach-Object { $_.TrimEnd() }
                $expectedOutput = Get-Content $expectedPath | ForEach-Object { $_.TrimEnd() }
                
                if (Compare-Object $actualOutput $expectedOutput -eq $null) {
                    Write-Host "✓ 測試通過 (執行時間: $([math]::Round($duration, 2))ms)" -ForegroundColor Green
                    $passedCount++
                } else {
                    Write-Host "✗ 測試失敗 (執行時間: $([math]::Round($duration, 2))ms)" -ForegroundColor Red
                    Write-Host "實際輸出:" -ForegroundColor Yellow
                    $actualOutput | ForEach-Object { Write-Host "  $_" }
                    Write-Host "預期輸出:" -ForegroundColor Yellow
                    $expectedOutput | ForEach-Object { Write-Host "  $_" }
                }
            } else {
                Write-Host "✗ 找不到輸出檔案" -ForegroundColor Red
            }
        } catch {
            Write-Host "✗ 程式執行錯誤: $_" -ForegroundColor Red
        }
    }
}

Write-Host "`n===================" -ForegroundColor Green
Write-Host "測試結果: $passedCount/$testCount 通過" -ForegroundColor $(if ($passedCount -eq $testCount) { "Green" } else { "Yellow" })

if ($passedCount -eq $testCount -and $testCount -gt 0) {
    Write-Host "🎉 所有測試都通過了！可以提交到 Online Judge 了！" -ForegroundColor Green
} elseif ($testCount -eq 0) {
    Write-Host "⚠️  沒有找到測試檔案，請確認測試資料格式正確" -ForegroundColor Yellow
} else {
    Write-Host "❌ 還有測試失敗，請檢查你的程式碼" -ForegroundColor Red
}
