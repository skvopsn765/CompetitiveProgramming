#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int getNumber(string str)
{
    if (str == "O") return 0;
    if (str == "A") return 1;
    if (str == "S") return 2;
    if (str == "AS") return 3;
    if (str == "SA") return 3;
}

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem2/input.txt", "r", stdin);
#endif

    map<pair<int, int>, map<int, int>> table = {};
    // O + O                   O:100
    table[{0, 0}][0] = 100;

    // O + A                   A:50、O:50
    table[{0, 1}][0] = 50;
    table[{0, 1}][1] = 50;

    // O + S                   S:50、O:50
    table[{0, 2}][0] = 50;
    table[{0, 2}][2] = 50;

    // O + AS                  A:50、S:50
    table[{0, 3}][1] = 50;
    table[{0, 3}][2] = 50;

    // A + A                   A:75、O:25
    table[{1, 1}][1] = 75;
    table[{1, 1}][0] = 25;

    // A + S                   A:25、S:25、O:25、AS:25
    table[{1, 2}][0] = 25;
    table[{1, 2}][1] = 25;
    table[{1, 2}][2] = 25;
    table[{1, 2}][3] = 25;

    // A + AS                  A:50、S:25、AS:25
    table[{1, 3}][1] = 50;
    table[{1, 3}][2] = 25;
    table[{1, 3}][3] = 25;

    // S + S                   S:75、O:25
    table[{2, 2}][2] = 75;
    table[{2, 2}][0] = 25;

    // S + AS                  A:25、S:50、AS:25
    table[{2, 3}][1] = 25;
    table[{2, 3}][2] = 50;
    table[{2, 3}][3] = 25;

    // AS + AS                 A:25、S:25、AS:50
    table[{3, 3}][1] = 25;
    table[{3, 3}][2] = 25;
    table[{3, 3}][3] = 50;

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        int i1 = getNumber(s1);
        int i2 = getNumber(s2);
        int i3 = getNumber(s3);
        auto outerIt = table.find(pair<int, int>{min(i1, i2), max(i1, i2)});
        if (outerIt != table.end())
        {
            auto innerMap = outerIt->second;
            auto pair = innerMap.find(i3);
            if (pair != innerMap.end())
            {
                cout << pair->second << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
