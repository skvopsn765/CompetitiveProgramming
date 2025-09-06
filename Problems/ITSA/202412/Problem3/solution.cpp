#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct merchent
{
    int index;
    int employee;
    int manager;
};

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem5/input.txt", "r", stdin);
#endif

    // 你的程式碼
    int n, k;
    cin >> n >> k;
    vector<merchent> v1(n);
    for (int i=0; i<n; i++)
    {
        v1[i].index = i;
        cin >> v1[i].employee >> v1[i].manager;
    }

    sort(v1.begin(), v1.end(), [](merchent a, merchent b)
    {
       return a.employee > b.employee;
    });

    vector<merchent> v2(v1.begin(), v1.begin() + k);
    sort(v2.begin(), v2.end(), [](merchent a, merchent b)
    {
        return a.manager > b.manager;
    });

    cout << v2[0].index + 1 << "\n";

    return 0;
}
