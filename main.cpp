#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int max_k = 10;
const int max_m = 100;
int arr[max_k][max_m];
const int INF = 0x3f3f3f3f;

int dfs(int k, int m)
{
    if (k == 0 || m == 0) return 0;
    if (k == 1) return m * (m + 1) / 2;
    if (arr[k][m] != 0) return arr[k][m];
    int min = INF;
    for (int x = 1; x <= m; x++)
    {
        int value = x + max(dfs(k-1, x-1), dfs(k, m-x));
        if (value < min) min = value;
    }
    arr[k][m] = min;

    return min;
}

int main()
{
#ifdef LOCAL
    freopen("Problems/UVA/UVA-882/input.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int k, m;
        scanf("%d", &k);
        scanf("%d", &m);
        int ans = dfs(k, m);
        printf("%d\n", ans);
    }

    return 0;
}
