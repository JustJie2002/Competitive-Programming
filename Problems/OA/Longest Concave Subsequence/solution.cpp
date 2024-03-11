/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 14:48:03
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;
using Info = pair<int, int>;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T> struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void add(T val) { ost.insert(make_pair(val, ++freq[val])); }
    void remove(T val) { ost.erase(make_pair(val, freq[val]--)); }
    int index(T val) { return ost.order_of_key(make_pair(val, -1)); }
    T operator[] (int i) const { return ost.find_by_order(i)->first; }

    T lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    T upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() { return ost.size(); }
    bool empty() { return ost.empty(); }
};

int main() {
    int n;
    scanf("%d", &n);

    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pos[-x].push_back(i);
    }

    SortedList<int> sl;
    int ans = 0, m = 0;
    for (const auto& [_, ids] : pos) {
        for (int id : ids) {
            sl.add(id);
            m++;
        }
        for (int id : ids) {
            int L = sl[0];
            int R = sl[m - 1];
            if (L < id) {
                auto not_less = sl.lower_bound(id) - 1;
                ans = max(ans, id - L + 1 - not_less);
            }
            if (R > id) {
                auto not_less = m - sl.upper_bound(id) - 1;
                ans = max(ans, R - id + 1 - not_less);
            }
        }
    }

    printf("%d\n", ans);
}

// ~ Just Jie