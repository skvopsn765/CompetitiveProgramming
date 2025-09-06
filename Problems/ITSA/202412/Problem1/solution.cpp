#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // Local testing: read from file
    #ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem1/input.txt", "r", stdin);
    #endif

    int count;
    cin >> count;

    vector<vector<int>> nums(count, vector<int>(2));
    double minMinutes = 50000;

    for (int i = 0; i < count; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }

    for (int i = 0; i < count; i++) {
        const double minutes = static_cast<double>(nums[i][0]) / static_cast<double>(nums[i][1]);
        if (minutes < minMinutes) {
            minMinutes = minutes;
        }
    }

    printf("%.1f\n", minMinutes / 60.0);

    return 0;
}
