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

    // 你的程式碼
    int interval;
    cin >> interval;

    string line;
    cin.ignore();
    getline(cin, line);

    string newStr;
    int index = 0;

    while (index < line.size())
    {
        newStr += line[index];
        index += interval + 1;
    }
    cout << newStr << endl;

    return 0;
}
