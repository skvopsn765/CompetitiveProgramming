#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem2/input.txt", "r", stdin);
#endif

    // 你的程式碼
    int n;
    cin >> n;
    int bought;
    int total;
    int acc;
    vector<int> v1;
    v1.reserve(n);
    vector<int> v2;
    v2.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
        while (total < v1[i])
        {
            bought++;
            total++;
            acc++;
            if (acc % 3 == 0)
            {
                total++;
                acc = 1;
            }
        }
        v2[i] = bought;
        bought = 0;
        total = 0;
        acc = 0;
    }

    for (int i=0; i<n; i++)
    {
        cout << v2[i] << "\n";
    }

    return 0;
}
