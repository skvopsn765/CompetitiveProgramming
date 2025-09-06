#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 使用記憶化來快取已計算的結果
unordered_map<int, int> cache;

int cycleLength(long long n) {
    if (n == 1) return 1;
    
    int originalN = n;
    int length = 0;
    
    // 計算直到遇到已知的值
    while (n >= originalN && cache.find(n) == cache.end()) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n = n / 2;
        }
        length++;
    }
    
    // 如果找到快取的值，加上它
    if (cache.find(n) != cache.end()) {
        length += cache[n];
    } else {
        // 遞迴計算剩餘部分
        length += cycleLength(n);
    }
    
    // 儲存結果到快取
    cache[originalN] = length;
    return length;
}

// 更快的版本，使用位運算和展開迴圈
int cycleLength_fast(long long n) {
    int length = 1;
    
    while (n != 1) {
        // 處理奇數：3n+1 然後除以2
        if (n & 1) {
            n = ((n * 3) + 1) >> 1;
            length += 2;
        } else {
            // 處理偶數：連續除以2直到變成奇數
            int trailing_zeros = __builtin_ctz(n);
            n >>= trailing_zeros;
            length += trailing_zeros;
        }
    }
    
    return length;
}

// 使用陣列快取（更快但使用更多記憶體）
const int MAX_CACHE = 1000000;
int memo[MAX_CACHE + 1] = {0};

int cycleLength_array(long long n) {
    if (n == 1) return 1;
    
    if (n <= MAX_CACHE && memo[n] != 0) {
        return memo[n];
    }
    
    long long original = n;
    int length = 0;
    
    // 計算直到數字小於等於 MAX_CACHE 或變成 1
    while (n > MAX_CACHE) {
        if (n & 1) {
            n = (3 * n + 1) >> 1;  // 奇數情況：3n+1 然後除以 2
            length += 2;
        } else {
            n >>= 1;  // 偶數情況：除以 2
            length++;
        }
    }
    
    // 加上剩餘部分的長度
    if (n <= MAX_CACHE) {
        if (memo[n] == 0) {
            memo[n] = cycleLength_array(n);
        }
        length += memo[n];
    }
    
    // 如果原始數字在快取範圍內，儲存結果
    if (original <= MAX_CACHE) {
        memo[original] = length;
    }
    
    return length;
}

int main() {
    // 關閉同步以加快 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Local testing: read from file
    #ifdef LOCAL
    freopen("Problems/UVA_100/input.txt", "r", stdin);
    #endif
    
    // 預先計算一些常用值
    memo[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        if (memo[i] == 0) {
            memo[i] = cycleLength_array(i);
        }
    }
    
    int i, j;
    while (cin >> i >> j) {
        int originalI = i, originalJ = j;
        
        if (i > j) {
            swap(i, j);
        }
        
        int maxCycle = 0;
        for (int k = i; k <= j; k++) {
            maxCycle = max(maxCycle, cycleLength_array(k));
        }
        
        cout << originalI << " " << originalJ << " " << maxCycle << "\n";
    }
    
    return 0;
}
