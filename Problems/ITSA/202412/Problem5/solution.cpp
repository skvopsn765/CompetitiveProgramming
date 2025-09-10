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

    int N, K;
    cin >> N >> K;
    struct merchent
    {
        int v1;
        int v2;
        int index;
    };
    vector<merchent> mv(N);
    mv.reserve(N);
    for (int i = 0; i < N; i++)
    {
        mv[i].index = i + 1;
        cin >> mv[i].v1 >> mv[i].v2;
    }

    sort(mv.begin(), mv.end(), [](merchent a, merchent b)
    {
        return a.v1 > b.v1;
    });

    vector<merchent> mv2(mv.begin(), mv.begin() + K);
    sort(mv2.begin(), mv2.end(), [](merchent a, merchent b)
    {
        return a.v2 > b.v2;
    });

    cout << mv2[0].index << "\n";

    return 0;
}
