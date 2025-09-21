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
    if (i > j) return 0;      // 區間已空：答案已確定（含測到 j 仍不爆），不需再花任何爆竹
    if (k == 0) return INF;   // 尚未確定且已無信箱可繼續測：此策略不可行，給極大成本避免被選
    if (arr[k][i][j] != -1) return arr[k][i][j];
    int result = INF;
    for (int x = i; x <= j; x++)
    {
        int val = x + max(dp(k - 1, i, x - 1), dp(k, x + 1, j));
        result = min(result, val);
    }
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
