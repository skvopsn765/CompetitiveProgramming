#define _CRT_SECURE_NO_WARNINGS  // 禁用 Visual Studio 安全性警告
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

// 常用常數定義
const int MAX_N = 100005;
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-9;

// 快速輸入輸出巨集
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// 本地測試時重新導向輸入輸出
#ifdef LOCAL
    #define DEBUG(x) cout << #x << " = " << x << endl;
#else
    #define DEBUG(x)
#endif

int main() {
    FAST_IO;
    
    // Local testing: read input from file
    // Option 1: Output to console (good for debugging)
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  // Comment this line to see output in console
    #endif
    
    // Option 2: Output to file (good for automated testing)
    // #ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    // 在這裡寫你的解題程式碼
    
    
    return 0;
}
