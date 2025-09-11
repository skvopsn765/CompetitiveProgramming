#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem7/input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> stack;
    stack.reserve(n + 2);
    stack.push_back(10e9);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (stack.back() <= v[i])
        {
            int r = v[i];
            int m = stack.back();
            stack.pop_back();
            int l = stack.back();
            ans += min(l, r);
        }
        stack.push_back(v[i]);
    }

    while (stack.size() > 2)
    {
        stack.pop_back();
        int l = stack.back();
        ans += l;
    }

    cout << ans << "\n";

    return 0;
}

