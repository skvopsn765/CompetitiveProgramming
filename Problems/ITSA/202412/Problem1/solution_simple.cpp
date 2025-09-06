#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Local testing: read from file
    #ifdef LOCAL
    freopen("Problems/Multiple_Jobs/input.txt", "r", stdin);
    #endif
    
    int count;
    cin >> count;
    
    double minMinutes = 50000;
    
    // 不需要儲存所有資料，直接處理
    for (int i = 0; i < count; i++) {
        int m, k;
        cin >> m >> k;
        double minutes = (double)m / (double)k;
        if (minutes < minMinutes) {
            minMinutes = minutes;
        }
    }
    
    printf("%.1f\n", minMinutes / 60.0);
    
    return 0;
}
