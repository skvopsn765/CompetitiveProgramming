#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
// 注意：原本開到 [100][1000][1000] 記憶體非常大（可能 MLE）。
int arr[11][105][105];

int dp(int k, int i, int j)
{
    if (i > j) return 0;
    if (k == 0) return INF;
    if (arr[k][i][j] != -1) return arr[k][i][j];

    int result = INF;

    // 【正確作法】：線性枚舉 x
    for (int x = i; x <= j; x++)
    {
        int broken = dp(k - 1, i, x - 1);
        int notBroken = dp(k, x + 1, j);
        int val = x + max(broken, notBroken);
        result = min(result, val);
    }

    // 【錯誤作法】：這段二分邏輯會 WA（保留說明，不再使用）
    // int lo = i;
    // int hi = j;
    // while (lo <= hi)
    // {
    //     int mid = (lo + hi) / 2;
    //     int broken = dp(k - 1, i, mid - 1);
    //     int notBroken = dp(k, mid + 1, j);
    //     int worst = mid + max(broken, notBroken);
    //     result = min(result, worst);
    //     if (broken < notBroken) lo = mid + 1;
    //     else hi = mid - 1;
    // }

    arr[k][i][j] = result;
    return result;
}

int main()
{
#ifdef LOCAL
    freopen("Problems/UVA/UVA-882/input.txt", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    memset(arr, -1, sizeof arr);
    while (N--)
    {
        int k, m;
        scanf("%d %d", &k, &m);
        int result = dp(k, 1, m);
        printf("%d\n", result);
    }

    return 0;
}
