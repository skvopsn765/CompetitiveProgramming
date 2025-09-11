// https://www.luogu.com.cn/problem/P1706

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000;
int n;
int st[N];
int arr[N];

void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%5d", arr[i]);
        }
        printf("\n");
        return;  // 修正：加上 return
    }

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])  // 修正：應該是 st[i] 不是 st[N]
        {
            st[i] = true;
            arr[x] = i;
            dfs(x + 1);
            st[i] = false;
            arr[x] = 0;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("Problems/Luogu/P1706-全排列问题/input.txt", "r", stdin);
    freopen("Problems/Luogu/P1706-全排列问题/output.txt", "w", stdout);
#endif

    scanf("%d", &n);
    dfs(1);
    return 0;
}
