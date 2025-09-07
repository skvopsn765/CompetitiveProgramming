#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem5/input.txt", "r", stdin);
#endif

    // 你的程式碼
    unordered_map<string, string> uoMap = {
        {"01", "East"},
        {"01", "East"},
        {"11", "West"},
        {"10", "South"},
        {"00", "North"},
        {"001", "30 Degrees"},
        {"110", "45 Degrees"},
        {"100", "60 Degrees"},
        {"010", "75 Degrees"},
        {"0100", "250 Miles"},
        {"1100", "700 Miles"},
        {"1010", "550 Miles"},
        {"0110", "100 Miles"},
    };

    int n;
    cin >> n;
    if (n <= 1 || n > 10) return 0;
    string code;
    cin >> code;
    string s1 = code.substr(0,2);
    string s2 = code.substr(2,3);
    string s3 = code.substr(5,4);
    string output = uoMap[s1] + " " + uoMap[s2] + " " + uoMap[s3];
    cout << output << "\n";
    return 0;
}
