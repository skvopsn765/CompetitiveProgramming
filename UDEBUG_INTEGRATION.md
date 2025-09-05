# uDebug 整合使用指南

## 🎯 專案結構說明

### 新的專案架構
```
CompetitiveProgramming/
├── Problems/UVA_100/
│   ├── solution.cpp          # 純 OJ 代碼（可直接複製到 Online Judge）
│   ├── test.cpp             # 測試類別（包含相同邏輯）
│   ├── input1.txt           # 範例測試輸入
│   ├── expected1.txt        # 範例預期輸出
│   ├── input.txt            # 當前測試輸入（從 uDebug 貼上）
│   ├── expected.txt         # 當前預期輸出（從 uDebug 貼上）
│   └── output.txt           # 程式執行結果
├── Utils/
│   ├── TestFramework.h      # 測試框架基類
│   └── IOManager.cpp        # 輸入輸出管理工具
└── Templates/               # 程式碼模板
```

## 🚀 使用流程

### 方法一：使用 Visual Studio（推薦）

1. **開啟 solution.cpp**
   - 這個檔案只包含純 OJ 代碼
   - 可以直接複製到 Online Judge 提交

2. **從 uDebug 複製測試資料**
   - 到 https://www.udebug.com/UVa/100
   - 複製輸入資料到 `Problems/UVA_100/input.txt`
   - 複製預期輸出到 `Problems/UVA_100/expected.txt`

3. **執行測試**
   - 設定 `Problems/UVA_100/test.cpp` 為啟動項目
   - 按 F5 執行測試
   - 查看結果比較

### 方法二：使用 IOManager 工具

1. **編譯 IOManager**
   ```bash
   g++ -o Utils/IOManager.exe Utils/IOManager.cpp
   ```

2. **執行 IOManager**
   ```bash
   Utils/IOManager.exe Problems/UVA_100
   ```

3. **互動式操作**
   - 選擇 1：貼上 uDebug 的輸入資料
   - 選擇 2：貼上 uDebug 的預期輸出
   - 選擇 3：查看程式執行結果
   - 選擇 4：比較輸出結果

## 📝 詳細步驟

### Step 1: 準備測試資料
1. 前往 uDebug 網站：https://www.udebug.com/UVa/11063
2. 選擇一個測試案例
3. 複製 Input 內容
4. 複製 Expected Output 內容

### Step 2: 設定測試環境
**選項 A - 手動設定：**
- 將 Input 貼到 `Problems/UVA_100/input.txt`
- 將 Expected Output 貼到 `Problems/UVA_100/expected.txt`

**選項 B - 使用 IOManager：**
- 執行 IOManager 工具
- 選擇對應選項貼上資料

### Step 3: 執行測試
1. 在 Visual Studio 中設定 `test.cpp` 為啟動項目
2. 按 F5 執行
3. 查看輸出結果

### Step 4: 提交到 OJ
1. 確認測試通過
2. 複製 `solution.cpp` 的完整內容
3. 貼到 Online Judge 提交

## 🔧 程式碼結構說明

### solution.cpp（純 OJ 代碼）
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

// 只包含解題邏輯，沒有測試相關代碼
int main() {
    // 解題代碼
    return 0;
}
```

### test.cpp（測試類別）
```cpp
#include "../../Utils/TestFramework.h"

class UVA100Test : public TestFramework {
    // 包含與 solution.cpp 相同的邏輯
    // 但整合了測試框架
};
```

## 🎯 優點

1. **純淨的 OJ 代碼**：solution.cpp 可直接提交
2. **方便的測試**：整合 uDebug 資料
3. **版本控制**：Git 管理程式碼歷史
4. **模組化設計**：測試邏輯與解題邏輯分離

## 🛠️ 進階使用

### 建立新題目
1. 複製 `Problems/UVA_100` 資料夾
2. 重新命名為新題目（如 `Problems/UVA_101`）
3. 修改 `solution.cpp` 和 `test.cpp` 中的邏輯
4. 從 uDebug 獲取測試資料

### Git 工作流程
```bash
# 開始新題目
git checkout -b uva-101

# 完成題目後
git add .
git commit -m "Solve UVA 101: The Blocks Problem"
git checkout main
git merge uva-101
```

## 🔍 疑難排解

### 常見問題
1. **編譯錯誤**：檢查 C++ 語法
2. **路徑問題**：確認工作目錄正確
3. **輸出不符**：檢查輸出格式（空格、換行）

### 偵錯技巧
1. 使用 Visual Studio 的偵錯功能
2. 在 test.cpp 中加入 DEBUG 輸出
3. 逐步檢查演算法邏輯

這個設定讓你可以高效地使用 uDebug 進行測試，同時保持程式碼的整潔和可提交性！
