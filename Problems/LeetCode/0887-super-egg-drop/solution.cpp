#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iso646.h>
using namespace std;

class Solution
{
public:
    int arr[105][10005];
    const int INF = 0x3f3f3f3f;

    int dp(int k, int n)
    {
        if (k == 0) return 0; // 這兩個是必須的，因為 DP 遞迴有可能會讓他們變成 0
        if (n == 0) return 1; // 這兩個是必須的，因為 DP 遞迴有可能會讓他們變成 0
        if (k == 1) return n;
        if (n == 1) return 1;
        if (arr[k][n] != -1) return arr[k][n];
        int result = INF;
        int l = 1;
        int r = n;
        int m = 0;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            int broken = dp(k - 1, m - 1);
            int notBroken = dp(k, n - m);
            if (broken > notBroken) r = m - 1;
            else if (broken < notBroken) l = m + 1;
            else break;
        }
        int val = 1 + max(dp(k - 1, m - 1), dp(k, n - m));
        result = min(result, val);
        arr[k][n] = result;
        return result;
    }

    int superEggDrop(int k, int n)
    {
        memset(arr, -1, sizeof arr);
        return dp(k, n);
    }
};

static inline void trim(string& s)
{
    auto notSpace = [](int ch) { return !isspace(ch); };
    s.erase(s.begin(), find_if(s.begin(), s.end(), notSpace));
    s.erase(find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
}

static bool readTwoIntsFlexible(istream& in, int& k, int& n)
{
    string line;
    if (!getline(in, line)) return false;
    trim(line);
    if (line.empty()) return false;

    if (line.find('=') != string::npos)
    {
        string t;
        t.reserve(line.size());
        for (char c : line)
        {
            if (isdigit((unsigned char)c) || c == '-') t.push_back(c);
            else t.push_back(' ');
        }
        stringstream ss(t);
        if (!(ss >> k)) return false;
        if (!(ss >> n)) return false;
        return true;
    }
    else
    {
        stringstream ss(line);
        if (!(ss >> k)) return false;
        if (!(ss >> n)) return false;
        return true;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("Problems/LeetCode/0887-super-egg-drop/input.txt", "r", stdin);
#endif

    int k = 0, n = 0;
    if (!readTwoIntsFlexible(cin, k, n))
    {
        if (!(cin >> k >> n)) return 0;
    }

    Solution sol;
    int answer = sol.superEggDrop(k, n);
    cout << answer << '\n';
    return 0;
}
