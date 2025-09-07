#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Local testing: read from file
    #ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem1/input.txt", "r", stdin);
    #endif

    // 你的程式碼
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        double distance, vFront, vBack, vRun;
        cin >> distance >> vFront >> vBack >> vRun;
        double ans = (distance / (vFront + vBack)) * vRun;
        // ans = static_cast<int>(ans * 100.0 + 0.5) / 100.0;
        ans = round(ans);
        printf("%.1f", ans);
    }

    return 0;
}
