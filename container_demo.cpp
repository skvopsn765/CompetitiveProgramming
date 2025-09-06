#include "container_demo.h"

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <iomanip>

using namespace std;

// ===== 序列式容器示範 =====
void demo_array()
{
    cout << "=== std::array ===\n";
    array<int, 5> a = {5, 1, 4, 2, 3};
    cout << "size=" << a.size() << " first=" << a[0] << "\n";
    sort(a.begin(), a.end());
    cout << "sorted:";
    for (auto x : a) cout << " " << x;
    cout << "\n\n";
}

void demo_vector()
{
    cout << "=== std::vector ===\n";
    vector<int> v;
    v.reserve(8); // 預先配置，減少重配
    v.push_back(3);
    v.push_back(1);
    v.emplace_back(4); // 就地建構
    v.insert(v.begin() + 1, 2); // 在第2個位置插入 2
    cout << "vector:";
    for (size_t i = 0; i < v.size(); ++i) cout << " " << v[i];
    cout << "\n";
    sort(v.begin(), v.end());
    cout << "sorted:";
    for (auto x : v) cout << " " << x;
    cout << "\n";
    v.erase(v.begin()); // 移除第一個
    cout << "after erase first:";
    for (auto x : v) cout << " " << x;
    cout << "\ncapacity=" << v.capacity() << " size=" << v.size() << "\n\n";
}

void demo_deque()
{
    cout << "=== std::deque ===\n";
    deque<int> dq;
    dq.push_back(2);
    dq.push_front(1);
    dq.push_back(3);
    cout << "deque:";
    for (auto x : dq) cout << " " << x;
    cout << "\nfront=" << dq.front() << " back=" << dq.back() << "\n";
    dq.pop_front();
    cout << "after pop_front:";
    for (auto x : dq) cout << " " << x;
    cout << "\n\n";
}

void demo_list()
{
    cout << "=== std::list ===\n";
    list<int> lst;
    lst.push_back(3);
    lst.push_front(1);
    auto it = lst.begin();
    ++it;
    lst.insert(it, 2); // 在中間插入 2
    cout << "list:";
    for (auto x : lst) cout << " " << x;
    cout << "\n";
    lst.remove_if([](int x) { return x % 2 == 1; }); // 移除奇數
    cout << "remove odd:";
    for (auto x : lst) cout << " " << x;
    cout << "\n\n";
}

void demo_forward_list()
{
    cout << "=== std::forward_list ===\n";
    forward_list<int> fl = {3, 2, 1};
    fl.push_front(4);
    cout << "forward_list:";
    for (auto x : fl) cout << " " << x;
    cout << "\n";
    auto prev = fl.before_begin();
    auto cur = fl.begin();
    while (cur != fl.end())
    {
        if (*cur == 2)
        {
            fl.erase_after(prev);
            break;
        } // 刪掉 2
        ++prev;
        ++cur;
    }
    cout << "after erase 2:";
    for (auto x : fl) cout << " " << x;
    cout << "\n\n";
}

// ===== 有序關聯式容器示範 =====
void demo_set_multiset()
{
    cout << "=== std::set / std::multiset ===\n";
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(2); // 重複不會新增
    cout << "set sorted unique:";
    for (auto x : s) cout << " " << x;
    cout << "\ncontains 2? " << (s.count(2) ? "yes" : "no") << "\n";
    s.erase(2);
    cout << "after erase 2:";
    for (auto x : s) cout << " " << x;
    cout << "\n";

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    cout << "multiset (allow dup):";
    for (auto x : ms) cout << " " << x;
    cout << "\n# of 1 = " << ms.count(1) << "\n\n";
}

void demo_map_multimap()
{
    cout << "=== std::map / std::multimap ===\n";
    map<string, int> mp;
    mp["alice"] = 90; // operator[] 建立或存取
    mp.insert(make_pair("bob", 80)); // insert
    cout << "alice=" << mp["alice"] << " size=" << mp.size() << "\n";
    auto it = mp.find("bob");
    if (it != mp.end()) cout << "found bob -> " << it->second << "\n";
    // lower_bound / upper_bound（字典序）
    auto lb = mp.lower_bound("a"); // >= "a"
    if (lb != mp.end()) cout << "lower_bound(a) -> " << lb->first << "\n";

    multimap<char, int> mmp; // key 可重複
    mmp.insert(make_pair('a', 1));
    mmp.insert(make_pair('a', 2));
    mmp.insert(make_pair('b', 3));
    auto range = mmp.equal_range('a'); // 取得同 key 的範圍
    cout << "multimap a ->";
    for (auto it2 = range.first; it2 != range.second; ++it2) cout << " " << it2->second;
    cout << "\n\n";
}

// ===== 無序關聯式容器示範 =====
void demo_unordered_set_map()
{
    cout << "=== std::unordered_set / std::unordered_map ===\n";
    unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    us.insert(3);
    cout << "unordered_set size=" << us.size() << " contains 1? " << (us.count(1) ? "yes" : "no") << "\n";

    unordered_map<string, int> um;
    um["dog"] = 1;
    um["cat"] = 2;
    cout << "unordered_map dog=" << um["dog"] << " cat=" << um["cat"] << "\n\n";
}

// ===== 容器配接器示範 =====
void demo_stack_queue_pq()
{
    cout << "=== std::stack / std::queue / std::priority_queue ===\n";
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "stack top=" << st.top() << "\n";
    st.pop();
    cout << "stack pop -> top=" << st.top() << "\n";

    queue<int> q;
    q.push(10);
    q.push(20);
    cout << "queue front=" << q.front() << " back=" << q.back() << "\n";
    q.pop();
    cout << "queue after pop front=" << q.front() << "\n";

    // 預設是最大堆（top 最大）
    priority_queue<int> mx;
    mx.push(5);
    mx.push(1);
    mx.push(7);
    cout << "max-heap top=" << mx.top() << "\n";
    mx.pop();
    cout << "max-heap after pop top=" << mx.top() << "\n";

    // 最小堆：使用 greater
    priority_queue<int, vector<int>, greater<int>> mn;
    mn.push(5);
    mn.push(1);
    mn.push(7);
    cout << "min-heap top=" << mn.top() << "\n\n";
}

// ===== 自訂比較器（在 set/map 中改排序準則） =====
struct Person
{
    string name;
    int score;
};

struct ByScoreThenName
{
    bool operator()(Person const& a, Person const& b) const
    {
        if (a.score != b.score) return a.score < b.score; // 小到大
        return a.name < b.name;
    }
};

void demo_custom_compare_set()
{
    cout << "=== custom comparator in std::set ===\n";
    set<Person, ByScoreThenName> people;
    people.insert({"Alice", 90});
    people.insert({"Bob", 85});
    people.insert({"Carol", 90}); // 分數同，按名字
    cout << "ordered by (score,name):\n";
    for (auto const& p : people)
    {
        cout << "  " << setw(5) << left << p.name << " " << p.score << "\n";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    demo_array();
    demo_vector();
    demo_deque();
    demo_list();
    demo_forward_list();
    demo_set_multiset();
    demo_map_multimap();
    demo_unordered_set_map();
    demo_stack_queue_pq();
    demo_custom_compare_set();

    return 0;
}
