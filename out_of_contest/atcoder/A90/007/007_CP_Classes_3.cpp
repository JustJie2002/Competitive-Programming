/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.04.2024 17:43:45
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

constexpr int inf = 1e9 + 5;

int main() {
    int n;
    scanf("%d", &n);

    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int w;
        scanf("%d", &w);
        auto it = s.upper_bound(w);
        int ans = inf;
        if (it != s.end()) {
            ans = *it - w;
        }
        if (it != s.begin()) {
            ans = min(ans, w - *prev(it));
        }
        printf("%d\n", ans);
    }
}

// ~ Just Jie