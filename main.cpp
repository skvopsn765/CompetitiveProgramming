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
        double d, f1, f2, fr;
        cin >> d >> f1 >> f2 >> fr;
        double fd = (d / (f1 + f2)) * fr;
        fd = (int)(fd * 100.0 + 0.5) / 100.0;
        printf("%.2f\n", fd);
    }

    return 0;
}
