/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 02:02:09
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 3>;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void add(T val) { ost.insert(make_pair(val, ++freq[val])); }
    void remove(T val) { ost.erase(make_pair(val, freq[val]--)); }
    int index(T val) { return ost.order_of_key(make_pair(val, -1)); }
    T operator[] (int i) const { return ost.find_by_order(i)->first; }

    int lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }
    int upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() { return ost.size(); }
    bool empty() { return ost.empty(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<int, Info> info;
    SortedList<Info> sl;
    for (int i = 1; i <= n; i++) {
        info[i] = {0, 0, i};
        sl.add(info[i]);
    }
    for (int e = 0; e < m; e++) {
        int t, p;
        cin >> t >> p;

        sl.remove(info[t]);
        info[t][0] -= 1;
        info[t][1] += p;
        sl.add(info[t]);

        cout << sl.index(info[1]) + 1 << "\n";
    }
}

// ~ JustJie