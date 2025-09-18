#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("Problems/UVA/UVA-882/input.txt", "r", stdin);
#endif
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int k, m;
        scanf("%d %d", &k, &m);
        // TODO: 實作解法
        // 這題不要求提供答案，僅建立題目模板與 I/O。
        printf("0\n");
    }
    return 0;
}

