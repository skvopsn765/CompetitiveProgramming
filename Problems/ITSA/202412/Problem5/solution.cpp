#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem5/input.txt", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    struct item
    {
        int first;
        int second;
        int index;
    };
    vector<item> itemV(n);
    for (int i = 0; i < n; i++)
    {
        itemV[i].index = i;
        cin >> itemV[i].first >> itemV[i].second;
    }
    sort(itemV.begin(), itemV.end(), [](item a, item b)
    {
        return a.first > b.first;
    });
    vector<item> itemV2(itemV.begin(), itemV.begin() + k);
    sort(itemV2.begin(), itemV2.end(), [](item a, item b)
    {
        return a.second > b.second;
    });

    cout << itemV2[0].index + 1 << "\n";

    return 0;
}
