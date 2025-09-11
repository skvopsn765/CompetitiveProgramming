param(
    [Parameter(Mandatory=$true)][int]$Id,
    [Parameter(Mandatory=$true)][string]$Slug
)

function Pad-Left4([int]$n) {
    return $n.ToString().PadLeft(4,'0')
}

$id4 = Pad-Left4 $Id
$dir = Join-Path "Problems/LeetCode" "$id4-$Slug"

if (-not (Test-Path $dir)) {
    New-Item -ItemType Directory -Path $dir | Out-Null
}

$solution = @"
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int MIN_VALUE = 0;
const int MAX_VALUE = 1000000000; // 1e9

static vector<int> readIntArrayFlexible(istream &in) {
    string s; vector<int> nums; if (!getline(in, s)) return nums;
    auto notSpace = [](int ch){ return !isspace(ch); };
    s.erase(s.begin(), find_if(s.begin(), s.end(), notSpace));
    s.erase(find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
    if (s.empty()) return nums;
    if (!s.empty() && s.front()=='[' && s.back()==']') {
        string t; for(char c: s){ if(c=='['||c==']'||c==',') c=' '; t.push_back(c);} 
        stringstream ss(t); long long x; while(ss>>x) nums.push_back((int)x); return nums;
    }
    { stringstream ss(s); long long x; while(ss>>x) nums.push_back((int)x);} return nums;
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
#ifdef LOCAL
    freopen("$dir/input.txt","r",stdin); freopen("$dir/output.txt","w",stdout);
#endif
    vector<int> nums = readIntArrayFlexible(cin);
    // TODO: 實作你的解法邏輯，以下為樣板：輸出輸入陣列長度
    cout << (int)nums.size() << "\n"; 
    return 0; }
"@

Set-Content -Path (Join-Path $dir "solution.cpp") -Value $solution -Encoding UTF8
Set-Content -Path (Join-Path $dir "input1.txt") -Value "[1,2,3]" -Encoding UTF8
Set-Content -Path (Join-Path $dir "expected1.txt") -Value "3" -Encoding UTF8
Set-Content -Path (Join-Path $dir "problem_description.txt") -Value "LeetCode $id4 - $Slug" -Encoding UTF8

Write-Host "已建立 $dir 並加入基本檔案。" -ForegroundColor Green


