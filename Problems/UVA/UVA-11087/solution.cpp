#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("Problems/UVA/UVA-11087/input.txt", "r", stdin);
#endif

    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int t = 1; t <= T; t++) {
        int n, k;
        scanf("%d %d", &n, &k);
        unordered_map<int,int> freq;
        freq.reserve((size_t)n * 2u);
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            freq[x]++;
        }
        vector<vector<int>> groups(k);
        vector<int> dupCount(k, 0);
        groups.shrink_to_fit();
        for (auto &p : freq) {
            int v = p.first;
            int c = p.second;
            int r = ((v % k) + k) % k;
            groups[r].push_back(v);
            if (c >= 2) dupCount[r]++;
        }
        long long ans = 0;
        for (int r = 0; r < k; r++) {
            int tr = (k - r) % k;
            if (r < tr) {
                ans += 1LL * groups[r].size() * groups[tr].size();
            } else if (r == tr) {
                long long s = (long long)groups[r].size();
                ans += s * (s - 1) / 2;
                ans += dupCount[r];
            }
        }
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
