/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.05.2024 10:12:16
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

constexpr int INF = int(1e9) + 5;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> adj1(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    int m;
    scanf("%d", &m);

    vector<vector<int>> adj2(m);
    for (int i = 1; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    auto bfs = [&](int root, const auto& adj) -> vector<int> {
        int n = adj.size();

        vector<int> dist(n, INF);
        queue<int> q;
        dist[root] = 0;
        q.push(root);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == INF) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }

        return dist;
    };

    auto find_centroid = [&](const auto& adj) -> int {
        int n = adj.size();

        vector<int> centroid, sz(n);
        y_combinator([&](auto&& dfs, int cur, int fa) -> void {
            sz[cur] = 1;
            bool is_centroid = true;
            for (int nei : adj[cur]) if (nei != fa) {
                dfs(nei, cur);
                sz[cur] += sz[nei];
                if (sz[nei] > n / 2) {
                    is_centroid = false;
                }
            }
            if (n - sz[cur] > n / 2) {
                is_centroid = false;
            }
            if (is_centroid) {
                centroid.push_back(cur);
            }
        })(0, -1);

        assert(!centroid.empty());
        return centroid[0];
    };

    auto a = find_centroid(adj1);
    auto b = find_centroid(adj2);

    dbg(a, b);

    // i64 ans = solve(a, adj1) + solve(b, adj2);

    // auto dis1 = bfs(a, adj1);
    // auto dis2 = bfs(b, adj2);

    // auto d1_siz = dis1.size();
    // auto d2_siz = dis2.size();

    // vector<int> dis(d1_siz + d2_siz + 1);

}

// ~ Just Jie