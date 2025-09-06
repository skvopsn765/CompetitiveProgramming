#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map<pair<string, string>, unordered_map<string, int>> build_table()
{
    unordered_map<pair<string, string>, unordered_map<string, int>> table;
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
};


int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem2/input.txt", "r", stdin);
#endif
    auto table = build_table();

    int round = 0;
    cin >> round;

    for (int i = 0; i < round; i++)
    {
        string L, R, T;
        cin >> L >> R >> T;

    }

    return 0;
}
