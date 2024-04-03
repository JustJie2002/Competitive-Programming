/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2023 21:01:20
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T> struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void add(T val) {
        ost.insert(make_pair(val, ++freq[val]));
    }
    
    void erase(T val) {
        ost.erase(make_pair(val, freq[val]--));
    }

    int order_of_key(T val) {
        return ost.order_of_key(make_pair(val, -1));
    }
    
    T find_by_order(T val) {
        return ost.find_by_order(val)->first;
    }

    T lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    T upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() {
        return ost.size();
    }

    bool empty() {
        return ost.empty();
    }
};

using i64 = long long;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    SortedList<int> perm;
    vector<int> is_good(n);
    int good = 0;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int j = perm.lower_bound(a[i]);
        int more = perm.size() - j;
        if (more == 1) {
            int big = perm.find_by_order(perm.size() - 1);
            freq[big]++;
        } else if (more == 0) {
            is_good[i] = 1;
            good++;
        }
        perm.add(a[i]);
    }

    int ans = -1, node = 0;
    for (int i = 0; i < n; i++) {
        int aft = good - is_good[i] + freq[a[i]];
        if (aft > ans) {
            ans = aft;
            node = a[i];
        } else if (aft == ans) {
            node = min(node, a[i]);
        }
    }

    printf("%d\n", node);
}

// ~ Jie ♥ Jenney