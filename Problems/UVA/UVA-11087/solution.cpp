#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// const int MAX_N = 100001;
// int arr[MAX_N];


int dp(int x)
{

}

int main()
{
#ifdef LOCAL
    freopen("Problems/UVA/UVA-11087/input.txt", "r", stdin);
#endif

    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int t = 1; t <= T; t++)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", arr[i]);
        }
        sort(arr.begin(), arr.end(), [](int a, int b)
        {
            return a < b;
        });



    }
    return 0;
}
