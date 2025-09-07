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

    map<pair<int, int>, map<int, int>> table = {
    };

    table[{0,0}][0] = 100;

    table[{0,1}][0] = 50;
    table[{0,1}][1] = 50;

    table[{0,2}][0] = 50;
    table[{0,2}][2] = 50;

    table[{0,3}][1] = 50;
    table[{0,3}][2] = 50;

    table[{1,1}][0] = 25;
    table[{1,1}][1] = 75;

    table[{1,2}][0] = 25;
    table[{1,2}][1] = 25;
    table[{1,2}][2] = 25;
    table[{1,2}][3] = 25;

    table[{1,3}][1] = 50;
    table[{1,3}][2] = 25;
    table[{1,3}][3] = 25;

    table[{2,2}][0] = 25;
    table[{2,2}][2] = 75;

   table[{2,3}][1] = 25;
   table[{2,3}][2] = 50;
   table[{2,3}][3] = 25;

   table[{3,3}][1] = 25;
   table[{3,3}][2] = 25;
   table[{3,3}][3] = 50;

    int count;
    cin >> count;

    for (int i=0; i<count; i++)
    {
        string first, second, result;
        cin >> first >> second >> result;
        int f = getNumber(first);
        int s = getNumber(second);
        int r = getNumber(result);
        pair<int, int> match = {min(f, s), max(f, s)};
        auto tree_iterator = table.find(match);
        if (tree_iterator != table.end())
        {
            auto& innerMap = tree_iterator->second;
            auto innerIt = innerMap.find(r);
            if (innerIt != innerMap.end())
            {
                cout << innerIt->second << "\n";
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


