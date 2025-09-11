param(
    [string]$Root = "Problems/LeetCode"
)

Write-Host "=== 執行全部 LeetCode 題目測試 ===" -ForegroundColor Green

if (-not (Test-Path $Root)) {
    Write-Host "沒有找到 $Root，略過。" -ForegroundColor Yellow
    exit 0
}

$problems = Get-ChildItem -Path $Root -Directory | Sort-Object Name
if ($problems.Count -eq 0) {
    Write-Host "$Root 內沒有題目資料夾" -ForegroundColor Yellow
    exit 0
}

$total = 0
$ok = 0

foreach ($p in $problems) {
    $path = Join-Path $Root $p.Name
    Write-Host "\n==> 測試: $path" -ForegroundColor Cyan
    $total++
    try {
        Utils\build_and_test.bat $path | Write-Host
        $ok++
    } catch {
        Write-Host "測試執行發生錯誤: $_" -ForegroundColor Red
    }
}

Write-Host "\n總結: $ok/$total 題目測試已執行完成（請上方各題輸出確認是否全通過）。" -ForegroundColor Green


