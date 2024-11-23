/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.17.2024 20:19:24
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    vector<bool> marked(n);
    y_combinator(
        [&](auto&& dfs, int u, int p) -> void {
            for (int v : adj[u]) {
                if (!marked[v] && v != p) {
                    dfs(v, u);
                }
            }

            if (p != u) {
                if (!marked[u] && !marked[p]) {
                    ans++;
                    marked[u] = true;
                    marked[p] = true;
                }
            }
        }
    )(0, 0);

    cout << ans << "\n";
}

// ~ Just Jie