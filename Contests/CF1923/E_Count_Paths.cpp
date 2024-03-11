/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.24.2024 00:14:37
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;

void workout(int tc) {
    int n;
    scanf("%d", &n);
    int m = n - 1;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        c[i]--;
    }

    vector<vector<int>> adj(n);
    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> p(n);
    i64 ans = 0;
    y_combinator([&](auto&& dfs, int cur, int fa) -> void {
        int cc = c[cur];
        int pre = p[cc];
        ans += pre;
        for (int nei : adj[cur]) {
            if (nei == fa) continue;
            p[cc] = 1;
            dfs(nei, cur);
        }
        p[cc] = pre + 1;
    })(0, 0);

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