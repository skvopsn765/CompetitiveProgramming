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
    while (n--)
    {
        int input = 0;
        scanf("%d", &input);
        int back = st.back();
        if (back <= input)
        {
            st.pop_back();
            st.push_back(input);
            ans += input;
        }
        else
        {
            st.push_back(input);
        }
    }

    while (st.size() > 2)
    {
        st.pop_back();
        int back = st.back();
        ans += back;
    }

    printf("%d\n", ans);

    return 0;
}
