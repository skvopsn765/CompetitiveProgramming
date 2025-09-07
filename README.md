# 競程練習專案 (Competitive Programming Practice)

這是一個專門用於 Online Judge 題目練習的 Visual Studio C++ 專案，讓你可以在本地方便地測試程式碼後再提交到 OJ 平台。

## 專案結構

```
CompetitiveProgramming/
├── Problems/           # 存放各個題目的解答
│   ├── UVA_100/       # UVA 範例題目
│   │   ├── solution.cpp        # 解題程式碼
│   │   ├── input.txt          # 測試輸入
│   │   ├── expected.txt       # 預期輸出
│   │   └── problem_description.txt  # 題目描述
│   └── ITSA/          # ITSA 題目分類
│       ├── 202411/    # 2024年11月
│       │   ├── Problem1/
│       │   ├── Problem2/
│       │   └── ...
│       └── 202412/    # 2024年12月
│           ├── Problem1/
│           ├── Problem2/
│           └── ...
├── Templates/          # 程式碼模板
│   ├── template.cpp           # 完整功能模板
│   └── basic_template.cpp     # 簡單模板
├── Utils/             # 工具程式
│   ├── TestFramework.h        # 測試框架
│   ├── test_runner.cpp        # 測試執行器
│   ├── IOManager.cpp          # 輸入輸出管理器
│   └── build_and_test.bat     # Windows 批次測試腳本
├── main.cpp           # 主執行檔（用於本地測試）
└── README.md          # 本說明文件
```

## 使用方法

### 1. 開始新題目

1. 在 `Problems/` 資料夾下建立新的題目資料夾，例如：
   - UVA 題目：`Problems/UVA_101/`
   - ITSA 題目：`Problems/ITSA/202411/Problem1/`
2. 複製模板檔案到題目資料夾：
   ```bash
   copy Templates\\template.cpp Problems\\UVA_101\\solution.cpp
   ```
3. 在題目資料夾中建立測試檔案：
   - `input.txt` (測試輸入)
   - `expected.txt` (預期輸出)
   - `problem_description.txt` (題目描述)

### 2. 編寫程式碼

在 `solution.cpp` 中編寫你的解題程式碼。模板已經包含：
- 常用的標頭檔
- 本地測試時的檔案輸入輸出重新導向
- 常用常數定義
- 快速輸入輸出設定

### 3. 測試程式碼

#### 方法一：使用 Visual Studio（推薦）
1. 將你的 `solution.cpp` 程式碼複製到 `main.cpp`
2. 修改 `main.cpp` 中的 `freopen` 路徑指向你的題目輸入檔案
3. 按 F5 執行並查看結果

#### 方法二：使用批次腳本
```bash
Utils\\build_and_test.bat Problems\\UVA_100
```

### 4. 提交到 Online Judge

測試通過後，將 `solution.cpp` 的內容複製到 OJ 平台提交。

**注意：** 提交時 `#ifdef LOCAL` 相關的程式碼會被自動忽略，因為 OJ 平台不會定義 `LOCAL` 巨集。

## 模板說明

### 完整模板 (template.cpp)
包含常用的標頭檔、常數定義、巨集等，適合複雜題目。

### 簡單模板 (basic_template.cpp)
只包含基本的輸入輸出重新導向，適合簡單題目。

## 測試檔案格式

- **輸入檔案：** `input.txt`
- **預期輸出檔案：** `expected.txt`
- **題目描述：** `problem_description.txt`
- 每個題目資料夾包含一組測試檔案

## 範例題目

專案包含以下範例題目：

1. **UVA 100** (The 3n + 1 problem) - 位於 `Problems/UVA_100/`
2. **ITSA 題目** - 位於 `Problems/ITSA/202411/` 和 `Problems/ITSA/202412/`

你可以：
1. 查看這些資料夾了解檔案結構
2. 在 Visual Studio 中打開並測試這些範例

## 支援的 Online Judge 平台

這個專案適用於大多數 OJ 平台，包括：
- UVa Online Judge
- ITSA 線上程式設計競賽
- Codeforces
- AtCoder
- LeetCode
- Codechef
- HackerRank

## 編譯器需求

- Visual Studio 2022 (推薦)
- 支援 C++17 的 MSVC 編譯器
- Windows 環境

## 常見問題

### Q: 為什麼需要 `#ifdef LOCAL`？
A: 這讓你可以在本地測試時從檔案讀取輸入，但提交到 OJ 時從標準輸入讀取。

### Q: 如何切換不同題目進行測試？
A: 將你要測試的 `solution.cpp` 程式碼複製到 `main.cpp`，並修改 `freopen` 路徑指向對應題目的 `input.txt`。

### Q: 測試失敗怎麼辦？
A: 檢查程式邏輯、邊界條件，或者檢查輸出格式是否完全符合預期（包括空格和換行）。

### Q: Problems 資料夾在 Visual Studio 中看不到？
A: Problems 資料夾設為 `None` 類型，會顯示在 Solution Explorer 中但不參與編譯，避免多個 `main` 函數衝突。

## 貢獻

歡迎提出改進建議或回報問題！
