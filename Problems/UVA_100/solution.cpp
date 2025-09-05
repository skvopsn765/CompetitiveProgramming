#include <iostream>
#include <algorithm>
using namespace std;

int cycleLength(int n) {
    int length = 1;
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n = n / 2;
        }
        length++;
    }
    return length;
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int originalI = i, originalJ = j;
        
        if (i > j) {
            swap(i, j);
        }
        
        int maxCycle = 0;
        for (int k = i; k <= j; k++) {
            maxCycle = max(maxCycle, cycleLength(k));
        }
        
        cout << originalI << " " << originalJ << " " << maxCycle << endl;
    }
    
    return 0;
}