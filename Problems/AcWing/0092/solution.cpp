// AcWing 92. 递归实现指数型枚举

#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100;
int n;
int st[N];

void dfs(int x)
{
    if (x > n)
    {
        for (int i=1; i<=n; i++)
        {
            if (st[i] == 1) printf("%d ", i);
        }
        printf("\n");
        return;
    }

    st[x] = 1;
    dfs(x + 1);
    st[x] = 0;

    st[x] = 2;
    dfs(x + 1);
    st[x] = 0;
}

int main()
{
#ifdef LOCAL
    freopen("Problems/AcWing/0092-exponential-enumeration/input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    dfs(1);
    return 0;
}
