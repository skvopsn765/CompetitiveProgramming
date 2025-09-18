#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_K = 15;
const int MAX_M = 105;

static long long arrMemo[MAX_K][MAX_M][MAX_M];
static unsigned char visitedMemo[MAX_K][MAX_M][MAX_M];

static long long tri(long long n) { return n * (n + 1) / 2; }

long long solveDP(int k, int i, int j) {
    if (i >= j) return 0;
    if (k == 1) return tri(j) - tri(i - 1);
    if (visitedMemo[k][i][j]) return arrMemo[k][i][j];
    long long best = 1LL<<62;
    for (int x = i; x <= j; x++) {
        long long cost = x;
        long long leftCost = solveDP(k - 1, i, x - 1);
        long long rightCost = solveDP(k, x + 1, j);
        long long worst = leftCost > rightCost ? leftCost : rightCost;
        long long total = cost + worst;
        if (total < best) best = total;
    }
    visitedMemo[k][i][j] = 1;
    arrMemo[k][i][j] = best;
    return best;
}

int main() {
#ifdef LOCAL
    freopen("Problems/UVA/UVA-882/input.txt", "r", stdin);
#endif
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int k, m;
        scanf("%d %d", &k, &m);
        memset(visitedMemo, 0, sizeof(visitedMemo));
        long long ans = solveDP(k, 1, m);
        printf("%lld\n", ans);
    }
    return 0;
}

