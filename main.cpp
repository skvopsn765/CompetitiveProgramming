#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int arr[100][1000][1000];

int dp(int k, int i, int j)
{
    if (i > j) return 0;
    if (k == 0) return INF;
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
