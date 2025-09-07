#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem3/input.txt", "r", stdin);
#endif

    // 你的程式碼
    int n;
    cin >> n;
    struct person
    {
        string personName;
        int point;
    };
    vector<person> result(n);
    for (int i = 0; i < n; i++)
    {
        string name;
        int height, a, b, c, d, e;
        cin >> name >> height >> a >> b >> c >> d >> e;
        result[i].personName = name;
        result[i].point = (height - 170) * 100 + 1000 + (a + b + c + d + e) * 20;
    }

    sort(result.begin(), result.end(), [](person a, person b)
    {
        return a.point > b.point;
    });

    for (int i=0; i<n; i++)
    {
        cout << result[i].personName << "\n";
    }

    return 0;
}
