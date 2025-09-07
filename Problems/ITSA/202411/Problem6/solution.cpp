#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem6/input.txt", "r", stdin);
#endif

    // 你的程式碼
    int n, m;
    cin >> n >> m;
    vector<string> row(m);
    vector<vector<string>> area(n);
    vector<pair<int, int>> numPos;
    for (int i = 0; i < n; i++)
    {
        string rowStr;
        cin >> rowStr;
        for (int j = 0; j < m; j++)
        {
            area[i][j] = rowStr[j];
            if (rowStr[j] >= '0' && rowStr[j] < 'A')
            {
                numPos.emplace_back(i, j);
            }
        }
    }

    // (a - 1, b - 1), (a - 1, b), (a - 1, b + 1)
    // (a    , b - 1), (a    , b), (a    , b + 1)
    // (a + 1, b - 1), (a + 1, b), (a + 1, b + 1)

    for (auto pos : numPos)
    {
        int a = pos.first;
        int b = pos.second;
        int bombCount = 0;
        for (int i = a - 1; i <= a + 1; i++)
        {
            if (i > n) continue;
            for (int j = b - 1; j <= b + 1; j++)
            {
                if (j > m) continue;
                if (area[i][j][0] == '*' || area[i][j][0] == '?')
                {
                    bombCount++;
                }
            }
        }

        if (bombCount != area[a][b][0] - '0') cout << "ERROR" << "\n";
    }

    cout << "PASS" << "\n";

    return 0;
}
