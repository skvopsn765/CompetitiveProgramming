#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::filesystem;
using namespace std::chrono;

class TestRunner {
private:
    string problemPath;
    string executableName;
    
public:
    TestRunner(const string& path) : problemPath(path) {
        // 從路徑中提取執行檔名稱
        executableName = path.substr(path.find_last_of("/\\") + 1);
    }
    
    // 編譯解題程式
    bool compile() {
        string sourceFile = problemPath + "/solution.cpp";
        string outputFile = problemPath + "/" + executableName + ".exe";
        
        // 使用 g++ 編譯，加上 LOCAL 定義
        string compileCommand = "g++ -DLOCAL -std=c++17 -O2 -o \"" + outputFile + "\" \"" + sourceFile + "\"";
        
        cout << "正在編譯: " << sourceFile << endl;
        cout << "編譯指令: " << compileCommand << endl;
        
        int result = system(compileCommand.c_str());
        if (result == 0) {
            cout << "編譯成功！" << endl;
            return true;
        } else {
            cout << "編譯失敗！" << endl;
            return false;
        }
    }
    
    // 執行單個測試案例
    bool runSingleTest(const string& inputFile, const string& expectedFile) {
        string execFile = problemPath + "/" + executableName + ".exe";
        string outputFile = problemPath + "/output.txt";
        
        // 複製輸入檔案到 input.txt
        copy_file(inputFile, problemPath + "/input.txt", copy_options::overwrite_existing);
        
        // 執行程式
        auto start = high_resolution_clock::now();
        int result = system(("\"" + execFile + "\"").c_str());
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<milliseconds>(end - start);
        
        if (result != 0) {
            cout << "程式執行錯誤！" << endl;
            return false;
        }
        
        // 比較輸出
        if (compareFiles(outputFile, expectedFile)) {
            cout << "✓ 測試通過 (執行時間: " << duration.count() << "ms)" << endl;
            return true;
        } else {
            cout << "✗ 測試失敗 (執行時間: " << duration.count() << "ms)" << endl;
            cout << "預期輸出與實際輸出不符" << endl;
            return false;
        }
    }
    
    // 比較兩個檔案內容
    bool compareFiles(const string& file1, const string& file2) {
        ifstream f1(file1), f2(file2);
        if (!f1.is_open() || !f2.is_open()) {
            cout << "無法開啟檔案進行比較" << endl;
            return false;
        }
        
        string line1, line2;
        while (getline(f1, line1) && getline(f2, line2)) {
            // 移除行尾空白
            while (!line1.empty() && isspace(line1.back())) line1.pop_back();
            while (!line2.empty() && isspace(line2.back())) line2.pop_back();
            
            if (line1 != line2) {
                cout << "差異發現:" << endl;
                cout << "實際輸出: \"" << line1 << "\"" << endl;
                cout << "預期輸出: \"" << line2 << "\"" << endl;
                return false;
            }
        }
        
        // 檢查是否有額外的行
        if (getline(f1, line1) || getline(f2, line2)) {
            cout << "檔案長度不同" << endl;
            return false;
        }
        
        return true;
    }
    
    // 執行所有測試
    void runAllTests() {
        if (!compile()) {
            return;
        }
        
        cout << "\n開始執行測試..." << endl;
        cout << "===================" << endl;
        
        int passedTests = 0;
        int totalTests = 0;
        
        // 尋找所有測試檔案
        for (const auto& entry : directory_iterator(problemPath)) {
            if (entry.is_regular_file()) {
                string filename = entry.path().filename().string();
                if (filename.find("input") == 0 && filename.find(".txt") != string::npos) {
                    string testNumber = filename.substr(5); // 移除 "input" 前綴
                    testNumber = testNumber.substr(0, testNumber.find(".txt"));
                    
                    string expectedFile = problemPath + "/expected" + testNumber + ".txt";
                    if (exists(expectedFile)) {
                        totalTests++;
                        cout << "\n測試案例 " << testNumber << ":" << endl;
                        if (runSingleTest(entry.path().string(), expectedFile)) {
                            passedTests++;
                        }
                    }
                }
            }
        }
        
        cout << "\n===================" << endl;
        cout << "測試結果: " << passedTests << "/" << totalTests << " 通過" << endl;
        
        if (passedTests == totalTests && totalTests > 0) {
            cout << "🎉 所有測試都通過了！可以提交到 Online Judge 了！" << endl;
        } else if (totalTests == 0) {
            cout << "⚠️  沒有找到測試檔案，請確認測試資料格式正確" << endl;
        } else {
            cout << "❌ 還有測試失敗，請檢查你的程式碼" << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "使用方法: test_runner <題目資料夾路徑>" << endl;
        cout << "範例: test_runner Problems/UVA_100" << endl;
        return 1;
    }
    
    string problemPath = argv[1];
    
    if (!exists(problemPath)) {
        cout << "錯誤: 找不到題目資料夾 " << problemPath << endl;
        return 1;
    }
    
    TestRunner runner(problemPath);
    runner.runAllTests();
    
    return 0;
}
