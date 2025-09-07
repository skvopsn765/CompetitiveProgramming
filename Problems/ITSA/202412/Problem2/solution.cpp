#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int getNumber(string str)
{
    if (str == "O") return 0;
    if (str == "A") return 1;
    if (str == "S") return 2;
    if (str == "AS") return 3;
    if (str == "SA") return 3;
}

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem2/input.txt", "r", stdin);
#endif


    return 0;
}


