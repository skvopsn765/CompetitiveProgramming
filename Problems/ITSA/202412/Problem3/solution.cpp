#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem3/input.txt", "r", stdin);
#endif

    int interval;
    cin >> interval;
    cin.ignore();
    string input;
    getline(cin, input);
    auto length = input.size();
    auto index = 0;
    string output;
    while (index < length)
    {
        output += input[index];
        index += (interval + 1);
    }

    cout << output << "\n";

    return 0;
}
