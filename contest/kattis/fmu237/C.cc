/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 14:12:32
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

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

constexpr i64 inf = i64(1e16) + 10;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

void work() {
    int n;
    // cin >> n;
    n = int(1e5) + 1;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        // cin >> a[i];
        a[i] = i;
    }

    int mx = *max_element(a.begin(), a.end());
    auto it = find(a.begin(), a.end(), mx);
    int mxi = it - a.begin();
    a.erase(it);

    const int m = n - 1;
    vector<i64> pre(m + 1);
    SortedList<int> sl;
    for (int i = 0; i < m; i++) {
        int x = a[i];
        pre[i + 1] = pre[i];
        int g = sl.upper_bound(x);
        sl.add(x);
        pre[i + 1] += (i - g);
    }

    vector<i64> suf(m + 1);
    SortedList<int> sl2;
    for (int i = m - 1; i >= 0; i--) {
        int x = a[i];
        suf[i] = suf[i + 1];
        int g = sl2.upper_bound(x);
        sl2.add(x);
        suf[i] += (m - i - 1) - g;
    }

    dbg(suf[0]);

    i64 ans = inf;
    for (int i = 0; i < n; i++) {
        i64 res = abs(mxi - i);
        res += pre[i];
        res += suf[i];
        ans = min(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie