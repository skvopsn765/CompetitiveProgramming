# 競程練習專案 (Competitive Programming Practice)

這是一個專門用於 Online Judge 題目練習的 Visual Studio C++ 專案，讓你可以在本地方便地測試程式碼後再提交到 OJ 平台。

## 專案結構

```
CompetitiveProgramming/
├── Problems/           # 存放各個題目的解答
│   └── UVA_100/       # 範例題目
│       ├── solution.cpp        # 解題程式碼
│       ├── input1.txt         # 測試輸入 1
│       ├── expected1.txt      # 預期輸出 1
│       ├── input2.txt         # 測試輸入 2
│       ├── expected2.txt      # 預期輸出 2
│       └── problem_description.txt  # 題目描述
├── Templates/          # 程式碼模板
│   ├── template.cpp           # 完整功能模板
│   └── basic_template.cpp     # 簡單模板
├── Utils/             # 工具程式
│   ├── test_runner.cpp        # 測試執行器
│   └── build_and_test.bat     # Windows 批次測試腳本
└── README.md          # 本說明文件
```

## 使用方法

### 1. 開始新題目

1. 在 `Problems/` 資料夾下建立新的題目資料夾，例如 `UVA_101`
2. 複製模板檔案到題目資料夾：
   ```bash
   copy Templates\\template.cpp Problems\\UVA_101\\solution.cpp
   ```
3. 在題目資料夾中建立測試檔案：
   - `input1.txt`, `input2.txt`, ... (測試輸入)
   - `expected1.txt`, `expected2.txt`, ... (預期輸出)

### 2. 編寫程式碼

在 `solution.cpp` 中編寫你的解題程式碼。模板已經包含：
- 常用的標頭檔
- 本地測試時的檔案輸入輸出重新導向
- 常用常數定義
- 快速輸入輸出設定

### 3. 測試程式碼

#### 方法一：使用批次腳本（推薦）
```bash
Utils\\build_and_test.bat Problems\\UVA_100
```

#### 方法二：手動編譯和執行
```bash
# 編譯測試執行器
g++ -std=c++17 -O2 -o Utils\\test_runner.exe Utils\\test_runner.cpp

# 執行測試
Utils\\test_runner.exe Problems\\UVA_100
```

### 4. 提交到 Online Judge

測試通過後，將 `solution.cpp` 的內容複製到 OJ 平台提交。

**注意：** 提交時記得移除或註解掉 `#ifdef LOCAL` 相關的程式碼，或者確保 OJ 平台不會定義 `LOCAL` 巨集。

## 模板說明

### 完整模板 (template.cpp)
包含常用的標頭檔、常數定義、巨集等，適合複雜題目。

### 簡單模板 (basic_template.cpp)
只包含基本的輸入輸出重新導向，適合簡單題目。

## 測試檔案格式

- **輸入檔案：** `input1.txt`, `input2.txt`, `input3.txt`, ...
- **預期輸出檔案：** `expected1.txt`, `expected2.txt`, `expected3.txt`, ...
- 檔案編號必須對應（input1.txt 對應 expected1.txt）

## 範例題目

專案包含 UVA 100 (The 3n + 1 problem) 作為範例，你可以：

1. 查看 `Problems/UVA_100/` 資料夾了解檔案結構
2. 執行測試來驗證環境設定：
   ```bash
   Utils\\build_and_test.bat Problems\\UVA_100
   ```

## 支援的 Online Judge 平台

這個專案適用於大多數 OJ 平台，包括：
- UVa Online Judge
- Codeforces
- AtCoder
- LeetCode
- Codechef
- HackerRank

## 編譯器需求

- 支援 C++17 的編譯器（推薦 g++ 或 Visual Studio）
- Windows 環境下可使用 MinGW 或 Visual Studio 的 MSVC

## 常見問題

### Q: 為什麼需要 `#ifdef LOCAL`？
A: 這讓你可以在本地測試時從檔案讀取輸入，但提交到 OJ 時從標準輸入讀取。

### Q: 如何處理多組測試資料？
A: 在題目資料夾中建立多個 input/expected 檔案對，測試執行器會自動執行所有測試。

### Q: 測試失敗怎麼辦？
A: 檢查程式邏輯、邊界條件，或者檢查輸出格式是否完全符合預期（包括空格和換行）。

## 貢獻

歡迎提出改進建議或回報問題！
