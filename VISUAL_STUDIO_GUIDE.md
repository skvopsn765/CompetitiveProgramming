# Visual Studio 使用指南

## 在 Visual Studio 中使用這個競程專案

### 1. 開啟專案
1. 啟動 Visual Studio
2. 檔案 → 開啟 → 專案/方案
3. 選擇 `CompetitiveProgramming.sln`

### 2. 設定主要執行檔案
由於專案包含多個 `.cpp` 檔案，你需要設定哪個檔案是主要執行檔案：

1. 在方案總管中找到你要執行的題目（例如 `Problems\UVA_100\solution.cpp`）
2. 右鍵點擊該檔案
3. 選擇「設定為啟動項目」

### 3. 編譯和執行
1. 按 `F5` 或點擊「開始偵錯」
2. 程式會自動從 `input.txt` 讀取輸入，並將結果寫入 `output.txt`

### 4. 測試流程

#### 方法一：使用 Visual Studio（推薦）
1. 將測試資料複製到題目資料夾中的 `input.txt`
2. 設定該題目的 `solution.cpp` 為啟動項目
3. 按 `F5` 執行
4. 檢查 `output.txt` 與預期輸出是否相符

#### 方法二：使用命令列（需要安裝 MinGW 或 Visual Studio Build Tools）
```cmd
# 在專案根目錄執行
cd Problems\UVA_100
copy input1.txt input.txt
g++ -DLOCAL -std=c++14 -O2 -o solution.exe solution.cpp
solution.exe
type output.txt
```

### 5. 新增題目的步驟

1. **建立題目資料夾**
   - 在 `Problems\` 下建立新資料夾，例如 `UVA_101`

2. **複製模板**
   - 複製 `Templates\template.cpp` 到新資料夾並重新命名為 `solution.cpp`

3. **加入 Visual Studio 專案**
   - 在方案總管中右鍵點擊專案
   - 新增 → 現有項目
   - 選擇新建立的 `solution.cpp`

4. **建立測試資料**
   - 在題目資料夾中建立 `input1.txt`, `expected1.txt` 等測試檔案

5. **編寫和測試**
   - 編寫解題程式碼
   - 設定為啟動項目並測試

### 6. 偵錯技巧

#### 設定中斷點
1. 在程式碼行號左側點擊設定中斷點
2. 按 `F5` 開始偵錯
3. 程式會在中斷點處暫停，你可以檢查變數值

#### 監看變數
1. 在偵錯模式下，將滑鼠移到變數上查看其值
2. 或在「監看式」視窗中新增要監看的變數

#### 逐步執行
- `F10`: 逐步執行（不進入函式）
- `F11`: 逐步執行（進入函式）
- `F5`: 繼續執行

### 7. 專案設定說明

#### 預處理器定義
專案已設定在 Debug 模式下定義 `LOCAL` 巨集，這樣：
- 本地測試時會從檔案讀取輸入
- 提交到 OJ 時會從標準輸入讀取

#### 編譯器設定
- 使用 C++14 或更高版本
- 最佳化設定適合競程需求

### 8. 提交到 Online Judge

測試通過後：
1. 複製 `solution.cpp` 的內容
2. 移除或確保 OJ 不會定義 `LOCAL` 巨集
3. 貼到 OJ 平台提交

### 9. 常見問題

**Q: 執行時找不到 input.txt**
A: 確認工作目錄設定正確，或使用絕對路徑。

**Q: 無法設定中斷點**
A: 確認是在 Debug 模式下編譯。

**Q: 程式執行後立即關閉**
A: 在程式結束前加入 `system("pause");` 或 `cin.get();`

### 10. 範例：測試 UVA_100

1. 開啟 Visual Studio，載入專案
2. 在方案總管中找到 `Problems\UVA_100\solution.cpp`
3. 右鍵設定為啟動項目
4. 確認 `input.txt` 包含測試資料：
   ```
   1 10
   100 200
   201 210
   900 1000
   ```
5. 按 `F5` 執行
6. 檢查 `output.txt` 是否包含正確結果：
   ```
   1 10 20
   100 200 125
   201 210 89
   900 1000 174
   ```

這樣你就可以在 Visual Studio 中方便地進行競程練習了！
