# 🚀 快速開始指南

## 方法一：使用 Visual Studio（最推薦）

### 1. 開啟專案
1. 雙擊 `CompetitiveProgramming.sln` 開啟 Visual Studio
2. 等待專案載入完成

### 2. 測試範例題目
1. 在方案總管中找到 `Problems\UVA_100\solution.cpp`
2. 右鍵點擊 → 設定為啟動項目
3. 按 `F5` 執行程式
4. 檢查專案資料夾中的 `output.txt` 檔案

### 3. 預期結果
執行後應該會在 `Problems\UVA_100\` 資料夾中產生 `output.txt`，內容應該是：
```
1 10 20
100 200 125
201 210 89
900 1000 174
```

## 方法二：使用 PowerShell 命令列

### 1. 開啟 PowerShell
在專案資料夾中開啟 PowerShell（右鍵 → 在終端機中開啟）

### 2. 執行測試
```powershell
# 執行 PowerShell 測試腳本
PowerShell -ExecutionPolicy Bypass -File Utils\test.ps1 Problems\UVA_100
```

### 3. 如果沒有 g++ 編譯器
如果看到編譯器相關錯誤，請：
- 安裝 MinGW-w64 或
- 使用 Visual Studio（方法一）

## 方法三：手動測試（如果其他方法都不行）

### 1. 準備測試資料
```powershell
# 複製測試輸入
Copy-Item Problems\UVA_100\input1.txt Problems\UVA_100\input.txt
```

### 2. 在 Visual Studio 中
1. 開啟 `Problems\UVA_100\solution.cpp`
2. 設定為啟動項目
3. 按 `F5` 執行
4. 檢查 `output.txt`

### 3. 比較結果
手動比較 `output.txt` 和 `expected1.txt` 的內容

## 🎯 開始新題目

### 1. 建立題目資料夾
```powershell
mkdir Problems\UVA_101
```

### 2. 複製模板
```powershell
Copy-Item Templates\template.cpp Problems\UVA_101\solution.cpp
```

### 3. 建立測試資料
在 `Problems\UVA_101\` 中建立：
- `input1.txt` - 測試輸入
- `expected1.txt` - 預期輸出

### 4. 在 Visual Studio 中加入檔案
1. 右鍵點擊專案 → 新增 → 現有項目
2. 選擇新建立的 `solution.cpp`

### 5. 編寫和測試
1. 編寫解題程式碼
2. 設定為啟動項目
3. 測試並偵錯

## ❓ 常見問題

**Q: PowerShell 說執行原則錯誤**
A: 使用 `PowerShell -ExecutionPolicy Bypass -File Utils\test.ps1 Problems\UVA_100`

**Q: 找不到 g++ 編譯器**
A: 使用 Visual Studio 方法，或安裝 MinGW-w64

**Q: Visual Studio 中程式執行後立即關閉**
A: 在程式結束前加入 `system("pause");`

**Q: 找不到 input.txt**
A: 確認檔案在正確的資料夾中，或使用絕對路徑

## 🎉 成功標誌

如果你看到以下輸出，表示一切正常：
```
1 10 20
100 200 125
201 210 89
900 1000 174
```

現在你可以開始解題了！記得測試通過後再提交到 Online Judge。
