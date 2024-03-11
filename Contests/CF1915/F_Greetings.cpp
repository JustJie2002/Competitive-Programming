/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.28.2023 14:44:56
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

using i64 = long long;
using Point = array<int, 2>;

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

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<Point> p(n);
    SortedList<int> sl;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i][0], &p[i][1]);
        sl.add(p[i][1]);
    }

    sort(p.begin(), p.end());

    i64 res = 0;
    for (int i = 0; i < n; i++) {
        // how many people have end points within p[i][0] to p[i][1]
        sl.erase(p[i][1]);
        res += sl.upper_bound(p[i][1]);
    }

    printf("%lld\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}