#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;


int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem2/input.txt", "r", stdin);
#endif

    map<pair<string, string>, map<string, int>> table = {};

    table[{"O", "O"}]["O"] = 100;

    table[{"O", "A"}]["O"] = 50;
    table[{"O", "A"}]["A"] = 50;

    table[{"O", "S"}]["O"] = 50;
    table[{"O", "S"}]["S"] = 50;

    table[{"O", "AS"}]["A"] = 50;
    table[{"O", "AS"}]["S"] = 50;

    table[{"A", "A"}]["A"] = 75;
    table[{"A", "A"}]["O"] = 25;

    table[{"A", "S"}]["A"] = 25;
    table[{"A", "S"}]["S"] = 25;
    table[{"A", "S"}]["O"] = 25;
    table[{"A", "S"}]["AS"] = 25;

    table[{"A", "AS"}]["A"] = 50;
    table[{"A", "AS"}]["S"] = 25;
    table[{"A", "AS"}]["AS"] = 25;

    table[{"S", "S"}]["S"] = 75;
    table[{"S", "S"}]["O"] = 25;

    table[{"S", "AS"}]["A"] = 25;
    table[{"S", "AS"}]["S"] = 50;
    table[{"S", "AS"}]["AS"] = 25;

    table[{"AS", "AS"}]["A"] = 25;
    table[{"AS", "AS"}]["S"] = 25;
    table[{"AS", "AS"}]["AS"] = 50;

    int n;
    cin >> n;
    struct my_struct
    {
        string first;
        string second;
        string result;
    };
    vector<my_struct> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second >> v[i].result;
        auto outterIt = table.find({v[i].first, v[i].second});
        if (outterIt != table.end())
        {
            auto innerMap = outterIt->second;
            auto innerIt = innerMap.find(v[i].result);
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
