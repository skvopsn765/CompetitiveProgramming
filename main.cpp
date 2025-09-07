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
        int N = 0;
        for (char j : input)
        {
            N += (j - '0');
        }
        int S = 1;
        for (int j = 2; j * j < N; j++)
        {
            if (N % j == 0)
            {
                S += j;
                if (j != N / j) S += N / j;
            }
        }
        if (S > N) cout << "-1" << "\n";
        if (S == N) cout << "0" << "\n";
        if (S < N) cout << N - S << "\n";
    }

    return 0;
}
