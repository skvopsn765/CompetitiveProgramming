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

        int buy = 0;
        int count = 0;
        while (count < target)
        {
            count++;
            buy++;
            if (count % 3 == 0)
            {
                count++;
            }
        }
        cout << buy << "\n";
    }

    return 0;
}
