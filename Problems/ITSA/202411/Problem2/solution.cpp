#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    // Local testing: read from file
    #ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem2/input.txt", "r", stdin);
    #endif

    // 你的程式碼
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int target;
        cin >> target;

        int sum;
        int count = 0;
        int total = 0;
        while (count < target)
        {
            total++;
            if (total % 3 == 0)
            {
                count++;
                total++;
            }
        }
        cout << total << "\n";
    }

    return 0;
}
