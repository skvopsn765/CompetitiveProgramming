#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
const int max_k = 10;
const int max_x = 100;
const int max_m = 100;
int dp[max_k][max_x][max_m];

int dfs(int k, int i, int j)
{
    if (i > j)
        return 0;

    if (k == 0)
        return INF;

    if (dp[k][i][j] != -1)
        return dp[k][i][j];

    int min = INF;

    for (int x = i; x <= j; x++)
    {
        int value = x + max(dfs(k - 1, i, x - 1), dfs(k, x + 1, j));
        if (value < min) min = value;
    }
    dp[k][i][j] = min;

    return min;
}

int main()
{
#ifdef LOCAL
    freopen("Problems/UVA/UVA-882/input.txt", "r", stdin);
#endif
    int C;
    scanf("%d", &C);
    memset(dp, -1, sizeof dp);
    while (C--)
    {
        int k, m;
        scanf("%d %d", &k, &m);
        int ans = dfs(k, 1, m);
        printf("%d\n", ans);
    }

    return 0;
}
