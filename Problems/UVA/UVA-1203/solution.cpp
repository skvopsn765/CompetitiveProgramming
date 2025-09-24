#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;


int main()
{
#ifdef LOCAL
    freopen("Problems/UVA/UVA-1203/input.txt", "r", stdin);
#endif

    struct item
    {
        int q_num;
        int period;
        int time;
        bool operator<(const item &a) const
        {
            if (time != a.time) return time > a.time;
            return q_num > a.q_num;
        }
    };

    char str[1000];
    priority_queue<item> pq;
    while (scanf("%s", str) && str[0] != '#')
    {
        const auto it = new item();
        scanf("%d", &it->q_num);
        scanf("%d", &it->period);
        it->time = it->period;
        pq.push(*it);
    }

    int N;
    scanf("%d", &N);
    while (N--)
    {
        auto it = pq.top();
        printf("%d\n", it.q_num);
        pq.pop();
        it.time += it.period;
        pq.push(it);
    }

    return 0;
}
