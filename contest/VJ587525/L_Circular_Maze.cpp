/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.16.2023 03:09:10
****************************************************************************************************/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using i64 = long long;
using Pair = pair<int, int>;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char nxt_char() {
    scanf(" %c", buf);
    return buf[0];
}

namespace JIE_TEMPLATE {

template <typename T> struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void insert(T val) {
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
}

using namespace JIE_TEMPLATE;

constexpr int MAX_RADIUS = 20, MAX_DEGREE = 360;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    SortedList<Pair> sl;

    for (; n--; ) {
        char op = nxt_char();

        if (op == 'C') {
            int r, t1, t2;
            scanf("%d%d%d", &r, &t1, &t2);
        } else if (op == 'S') {
            int r1, r2, t;
            scanf("%d%d%d", &r1, &r2, &t);
        } else assert(false);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney