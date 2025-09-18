#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_K = 15;
const int MAX_M = 105;
const int INF_COST = 0x3f3f3f3f;

static int arrMemo[MAX_K][MAX_M][MAX_M];
static unsigned char visitedMemo[MAX_K][MAX_M][MAX_M];

static int tri(int n) { return n * (n + 1) / 2; }

int solveDP(int k, int i, int j) {
    if (i > j) return 0;
    if (i == j) return i;
    if (k == 1) return tri(j) - tri(i - 1);
    if (visitedMemo[k][i][j]) return arrMemo[k][i][j];
    int best = INF_COST;
    for (int x = i; x <= j; x++) {
        best = min(best, x + max(solveDP(k - 1, i, x - 1), solveDP(k, x + 1, j)));
    }
    visitedMemo[k][i][j] = 1;
    arrMemo[k][i][j] = best;
    return best;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int k, m;
        scanf("%d %d", &k, &m);
        memset(visitedMemo, 0, sizeof(visitedMemo));
        int ans = solveDP(k, 1, m);
        printf("%d\n", ans);
    }
    return 0;
}

