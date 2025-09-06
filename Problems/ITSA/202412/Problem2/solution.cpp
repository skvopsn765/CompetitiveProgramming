#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202412/Problem2/input.txt", "r", stdin);
#endif

    // 你的程式碼
    vector<string> words;
    map<string, int> wordCount;
    string word;
    while (cin >> word)
    {
        words.push_back(word);
        wordCount[word]++;
    }
    for (const auto& w : words)
    {
        if (wordCount[w] == 1)
        {
            cout << w << endl;
        }
    }

    return 0;
}
