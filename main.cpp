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
    stack<int> s;
    int ans = 0;
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
        if (s.empty()) s.push(v[i]);
        else
        {
            // [10, 5]
            // ans = 8;
            // [10, 8]
            // ans = 18;

            if (s.top() <= v[i])
            {
                s.pop();
                s.push(v[i]);
                ans += v[i];
            }
            else
            {
                s.push(v[i]);
            }
        }
    }

    while (s.size() > 1)
    {
        ans += s.top();
        s.pop();
    }

    cout << ans << "\n";

    return 0;
}
