#include "../../Utils/TestFramework.h"
#include <iostream>
#include <fstream>
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
    
    // 從 input.txt 載入測試資料，從 expected.txt 載入預期輸出
    test.loadInputFromFile("input.txt");
    
    // 讀取預期輸出
    ifstream expectedFile("Problems/UVA_100/expected.txt");
    if (expectedFile.is_open()) {
        string expected, line;
        while (getline(expectedFile, line)) {
            expected += line + "\n";
        }
        expectedFile.close();
        test.setExpectedOutput(expected);
    }
    
    // 執行測試
    test.runTest();
    
    return 0;
}
