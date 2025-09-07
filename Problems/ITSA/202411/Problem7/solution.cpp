#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    // Local testing: read from file
    #ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem7/input.txt", "r", stdin);
    #endif

    // 你的程式碼
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    vector<int> a;
    a.reserve(n + 2);
    int INF = 10e9;
    a.push_back(INF);

    for (int i=0; i<n; i++)
    {
        int x = v[i];
        while (a.back() <= x)
        {
            int r = x;
            a.pop_back();
            int l = a.back();
            ans += min(l, r);
        }
        a.push_back(x);
    }

    while (a.size() > 2)
    {
        a.pop_back();
        int l = a.back();
        ans += l;
    }

    cout << ans << "\n";

    return 0;
}
