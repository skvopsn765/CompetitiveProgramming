// AcWing 92. 递归实现指数型枚举

#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> path;

void dfs(int u) {
    if (u > n) {
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) printf(" ");
            printf("%d", path[i]);
        }
        printf("\n");
        return;
    }
    
    // 不選當前數字
    dfs(u + 1);
    
    // 選當前數字
    path.push_back(u);
    dfs(u + 1);
    path.pop_back();
}

int main() {
#ifdef LOCAL
    freopen("Problems/AcWing/0092-exponential-enumeration/input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    dfs(1);
    return 0;
}
