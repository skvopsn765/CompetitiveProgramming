#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        return 0;
    }
};

static inline void trim(string &s) {
    auto notSpace = [](int ch){ return !isspace(ch); };
    s.erase(s.begin(), find_if(s.begin(), s.end(), notSpace));
    s.erase(find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
}

static bool readTwoIntsFlexible(istream &in, int &k, int &n) {
    string line;
    if (!getline(in, line)) return false;
    trim(line);
    if (line.empty()) return false;

    if (line.find('=') != string::npos) {
        string t; t.reserve(line.size());
        for (char c : line) {
            if (isdigit((unsigned char)c) || c=='-' ) t.push_back(c);
            else t.push_back(' ');
        }
        stringstream ss(t);
        if (!(ss >> k)) return false;
        if (!(ss >> n)) return false;
        return true;
    } else {
        stringstream ss(line);
        if (!(ss >> k)) return false;
        if (!(ss >> n)) return false;
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("Problems/LeetCode/0887-super-egg-drop/input.txt", "r", stdin);
#endif

    int k = 0, n = 0;
    if (!readTwoIntsFlexible(cin, k, n)) {
        if (!(cin >> k >> n)) return 0;
    }

    Solution sol;
    int answer = sol.superEggDrop(k, n);
    cout << answer << '\n';
    return 0;
}


