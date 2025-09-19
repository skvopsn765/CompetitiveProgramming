#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define maxk 10+5
#define maxm 100+5
#define INF 0x3f3f3f3f

int dp[maxk][maxm][maxm];
bool visited[maxk][maxm][maxm];

int dfs(int k, int i, int j)
{
    if (i > j)
        return 0;

    if (k == 0)
        return INF;

    if (visited[k][i][j])
        return dp[k][i][j];

    visited[k][i][j] = true;
    int& ret = dp[k][i][j];

    int x;
    ret = INF;

    for (x = i; x <= j; x++)
        ret = min(ret, x + max(dfs(k - 1, i, x - 1), dfs(k, x + 1, j)));

    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("Problems/UVA/UVA-882/input.txt", "r", stdin);
#endif
    int Cas, k, m;
    memset(visited, false, sizeof(visited));
    scanf("%d", &Cas);

    while (Cas--)
    {
        scanf("%d %d", &k, &m);
        printf("%d\n", dfs(k, 1, m));
    }
    return 0;
}
