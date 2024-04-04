/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.03.2024 21:00:48
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
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dep(n);
    int a = 0;
    auto dfs = y_combinator([&](auto&& dfs, int cur, int fa, int depth) -> void {
        dep[cur] = depth;
        if (dep[cur] > dep[a]) {
            a = cur;
        }
        for (int nei : adj[cur]) {
            if (nei != fa) {
                dfs(nei, cur, depth + 1);
            }
        }
    });
    dfs(0, 0, 0);
    dfs(a, a, 0);

    int mx = *max_element(dep.begin(), dep.end());
    printf("%d\n", mx + 1);
}

// ~ Just Jie