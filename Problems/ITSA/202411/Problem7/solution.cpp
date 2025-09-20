#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    // Local testing: read from file
#ifdef LOCAL
    freopen("Problems/ITSA/202411/Problem7/input.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector<int> st;
    st.push_back(INF);
    int ans = 0;
    int ele = 0;
    scanf("%d", &ele);
    st.push_back(ele);
    while (st.size() > 2)
    {
        scanf("%d", &ele);
        int back = st.back();
        if (back <= ele)
        {
            st.pop_back();
            st.push_back(ele);
            ans += back;
        }
    }

    printf("%d\n", ans);

    return 0;
}
