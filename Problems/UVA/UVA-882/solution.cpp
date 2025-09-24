#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int arr[11][105][105];

int dp(int k, int i, int j)
{
    // 邊界1：區間為空 → 答案已確定
    if (i > j) return 0;

    // 邊界2：沒有信箱但還需測試 → 策略不可行
    if (k == 0) return INF;

    // 記憶化：避免重複計算
    if (arr[k][i][j] != -1) return arr[k][i][j];

    int result = INF;
    // 嘗試所有可能的測試點
    for (int x = i; x <= j; x++)
    {
        // 計算選擇 x 的總成本
        int cost_explode = dp(k - 1, i, x - 1);     // 炸毀情況
        int cost_survive = dp(k, x + 1, j);         // 未炸毀情況
        int total_cost = x + max(cost_explode, cost_survive);  // 最壞情況
        result = min(result, total_cost);           // 選最優策略
    }

    return arr[k][i][j] = result;
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
        printf("%d\n", dp(k, 1, m));
    }

    return 0;
}
