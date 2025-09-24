#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem7/input.txt", "r", stdin);
#endif

    int N;
    scanf("%d", &N);
    vector<int> v;
    v.push_back(INF);
    int ans = 0;
    while (N--)
    {
        int val = 0;
        scanf("%d", &val);
        if (v.back() <= val)
        {
            ans += val;
            v.pop_back();
        }
        v.push_back(val);
    }

    while (v.size() > 2)
    {
        v.pop_back();
        ans += v.back();
    }

    printf("%d\n", ans);

    return 0;
}
