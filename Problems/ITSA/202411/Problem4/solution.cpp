#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem4/input.txt", "r", stdin);
#endif

    // 你的程式碼
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        int N;
        for (int j = 0; j < input.size(); j++)
        {
            N += (input[i] - '0');
        }
        vector<int> factor;
        int S;
        for (int j = 1; j < N; j++)
        {
            if (N % j == 0)
            {
                factor.push_back(j);
                S += j;
            }
        }
        if (S > N) cout << "-1" << "\n";
        if (S = N) cout << "0" << "\n";
        if (S < N) cout << N - S << "\n";
    }

    return 0;
}
