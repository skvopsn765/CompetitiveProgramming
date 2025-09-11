#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

// 常數定義（避免 Magic Number）
const int MIN_VALUE = 0;
const int MAX_VALUE = 1000000000; // 1e9

// 輔助：從輸入讀取一行，嘗試解析為 JSON 陣列或空白分隔整數
static vector<int> readIntArrayFlexible(istream &in) {
    string s;
    vector<int> nums;
    if (!getline(in, s)) return nums;
    // 去除前後空白
    auto notSpace = [](int ch){ return !isspace(ch); };
    s.erase(s.begin(), find_if(s.begin(), s.end(), notSpace));
    s.erase(find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
    if (s.empty()) return nums;

    // 若為 JSON 形式 [a,b,c]
    if (!s.empty() && s.front() == '[' && s.back() == ']') {
        string t;
        for (char c : s) {
            if (c == '[' || c == ']' || c == ',') c = ' ';
            t.push_back(c);
        }
        stringstream ss(t);
        long long x;
        while (ss >> x) nums.push_back((int)x);
        return nums;
    }

    // 否則視為空白分隔
    {
        stringstream ss(s);
        long long x;
        while (ss >> x) nums.push_back((int)x);
    }
    return nums;
}

// 你的題目邏輯：以 LeetCode 0198 House Robber 為例
// 可直接替換為任何單函式/類別解法，主函式只負責 I/O
static int robHouseMaxAmount(const vector<int>& nums) {
    long long prevNotRob = 0;  // dp[i-1][0]
    long long prevRob = 0;     // dp[i-1][1]
    for (int value : nums) {
        long long notRob = max(prevNotRob, prevRob);
        long long rob = prevNotRob + value;
        prevNotRob = notRob;
        prevRob = rob;
    }
    return (int)max(prevNotRob, prevRob);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // 輸入一行陣列，輸出單一整數結果
    vector<int> nums = readIntArrayFlexible(cin);
    int answer = robHouseMaxAmount(nums);
    cout << answer << "\n";
    return 0;
}


