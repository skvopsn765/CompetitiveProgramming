#include "../../Utils/TestFramework.h"
#include <iostream>
#include <algorithm>
using namespace std;

class UVA100Test : public TestFramework {
public:
    UVA100Test() : TestFramework("Problems/UVA_100") {}
    
private:
    int cycleLength(int n) {
        int length = 1;
        while (n != 1) {
            if (n % 2 == 1) {
                n = 3 * n + 1;
            } else {
                n = n / 2;
            }
            length++;
        }
        return length;
    }
    
public:
    void solveProblem() override {
        // 這裡包含與 solution.cpp 相同的邏輯
        
        int i, j;
        while (cin >> i >> j) {
            int originalI = i, originalJ = j;
            
            if (i > j) {
                swap(i, j);
            }
            
            int maxCycle = 0;
            for (int k = i; k <= j; k++) {
                maxCycle = max(maxCycle, cycleLength(k));
            }
            
            cout << originalI << " " << originalJ << " " << maxCycle << endl;
        }
    }
};

int main() {
    UVA100Test test;
    
    // 方法一：從檔案載入測試資料
    test.loadInputFromFile("input1.txt");
    test.setExpectedOutput("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");
    test.runTest();
    
    // 方法二：手動設定測試資料（從 uDebug 複製貼上）
    cout << "\n=== Manual Test (paste from uDebug) ===" << endl;
    cout << "Paste your input here and press Enter twice:" << endl;
    
    string input, line;
    while (getline(cin, line) && !line.empty()) {
        input += line + "\n";
    }
    
    if (!input.empty()) {
        test.setInput(input);
        
        cout << "Paste expected output (optional, press Enter twice to skip):" << endl;
        string expected;
        while (getline(cin, line) && !line.empty()) {
            expected += line + "\n";
        }
        
        if (!expected.empty()) {
            test.setExpectedOutput(expected);
        }
        
        test.runTest();
    }
    
    return 0;
}
