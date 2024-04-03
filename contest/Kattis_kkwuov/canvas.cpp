/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 18:02:16
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

constexpr int N = 1e5 + 1;
constexpr i64 inf = 1e18 + 10;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    priority_queue<i64, vector<i64>, greater<i64>> pq;
    for (int i = 0; i < n; i++) {
        i64 x;
        scanf("%lld", &x);
        pq.push(x);
    }

    i64 ans = 0;
    while (pq.size() > 1) {
        i64 x = pq.top(); pq.pop();
        i64 y = pq.top(); pq.pop();
        i64 z = x + y;
        ans += z;
        pq.push(z);
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie