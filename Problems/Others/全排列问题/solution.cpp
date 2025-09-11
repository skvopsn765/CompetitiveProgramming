// https://www.luogu.com.cn/problem/P1706

#include <cstdio>

using namespace std;
const int N = 1000;
int n;
int arr[N];
bool st[N];

void dfs(int x) {
    if (x > n) {
        for (int i = 1; i <= n; i++) {
            printf("%5d", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            st[i] = true;
            arr[x] = i;
            dfs(x + 1);
            st[i] = false;
            arr[x] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}
