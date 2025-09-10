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

    int n;
    cin >> n;
    string input;
    cin.ignore();
    getline(cin, input);
    int index = 0;
    string ans;
    while (index < input.size())
    {
        ans += input[index];
        index += n + 1;
    }

    printf("%s", ans.c_str());
    // cout << ans << endl;

    return 0;
}
