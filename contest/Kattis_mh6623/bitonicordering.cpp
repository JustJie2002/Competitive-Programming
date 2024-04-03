/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.30.2024 02:37:57
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

constexpr i64 INF = i64(1e18) + 10;

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

    vector<int> a(n);
    int peak = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        peak = max(peak, a[i]);
    }

    vector<i64> pre(n + 1), suf(n + 1);
    SortedList<int> sl1;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        sl1.add(a[i]);
        int j = sl1.index(a[i]);
        pre[i + 1] += i - j;
    }
    SortedList<int> sl2;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1];
        sl2.add(a[i]);
        int j = sl2.index(a[i]);
        suf[i] += (n - 1 - i) - j;
    }

    i64 ans = INF;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, pre[i] + suf[i]);
    }

    printf("%lld\n", ans);
}

// ~ Just Jie