#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// 簡化版測試工具，不依賴 C++17 filesystem
int main() {
    cout << "=== 競程測試工具 ===" << endl;
    cout << "正在測試 UVA_100 範例題目..." << endl;
    
    // 編譯解題程式
    string compileCmd = "g++ -DLOCAL -std=c++14 -O2 -o Problems/UVA_100/solution.exe Problems/UVA_100/solution.cpp";
    cout << "編譯指令: " << compileCmd << endl;
    
    int result = system(compileCmd.c_str());
    if (result != 0) {
        cout << "編譯失敗！請確認：" << endl;
        cout << "1. 已安裝 g++ 編譯器" << endl;
        cout << "2. solution.cpp 語法正確" << endl;
        return 1;
    }
    
    cout << "編譯成功！" << endl;
    
    // 測試第一組資料
    cout << "\n測試案例 1:" << endl;
    system("copy Problems\\UVA_100\\input1.txt Problems\\UVA_100\\input.txt > nul");
    system("Problems\\UVA_100\\solution.exe");
    
    cout << "實際輸出:" << endl;
    system("type Problems\\UVA_100\\output.txt");
    cout << "\n預期輸出:" << endl;
    system("type Problems\\UVA_100\\expected1.txt");
    
    cout << "\n請手動比較輸出結果。" << endl;
    cout << "如果相符，你的程式碼就可以提交到 Online Judge 了！" << endl;
    
    return 0;
}
