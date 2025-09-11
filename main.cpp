#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

// 常數定義（避免 Magic Number）
const int MIN_VALUE = 0;
const int MAX_VALUE = 1000000000; // 1e9

class Solution {
public:
    int rob(vector<int>& nums) {
        int a,b,c;
        a=0;b=0;c=0;
        for (int i=0; i<nums.size(); i++)
        {
            a = max(b, c+nums[i]);
            c = b;
            b = a;
        }

        return a;
    }
};

// 讀取一行並解析為整數陣列
// 支援兩種格式：
// 1) JSON 陣列，如: [2,7,9,3,1]
// 2) 空白分隔，如: 2 7 9 3 1
static vector<int> readIntArrayFlexible(istream& in)
{
    vector<int> nums;
    string line;
    if (!getline(in, line)) {
        return nums;
    }
    // 去除 UTF-8 BOM（若存在）
    if (line.size() >= 3 && (unsigned char)line[0] == 0xEF && (unsigned char)line[1] == 0xBB && (unsigned char)line[2] == 0xBF) {
        line.erase(0, 3);
    }
    // 去除前後空白
    auto notSpace = [](int ch) { return !isspace(ch); };
    line.erase(line.begin(), find_if(line.begin(), line.end(), notSpace));
    line.erase(find_if(line.rbegin(), line.rend(), notSpace).base(), line.end());
    if (line.empty()) return nums;

    if (line.find('[') != string::npos && line.find(']') != string::npos) {
        string t;
        t.reserve(line.size());
        for (char c : line) {
            if (c == '[' || c == ']' || c == ',') c = ' ';
            t.push_back(c);
        }
        stringstream ss(t);
        long long x;
        while (ss >> x) nums.push_back((int)x);
        return nums;
    }

    {
        stringstream ss(line);
        long long x;
        while (ss >> x) nums.push_back((int)x);
    }
    return nums;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("Problems/LeetCode/0198-house-robber/input.txt", "r", stdin);
#endif

    const auto solution = new Solution();
    vector<int> nums = readIntArrayFlexible(cin);
    const int answer = solution->rob(nums);
    cout << answer << "\n";
    return 0;
}
