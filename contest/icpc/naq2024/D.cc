/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 15:27:26
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<Info>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    map<int, i64> t;
    for (int i = 0; i < n; i++) {
        t[c[i]]++;
    }

    vector<map<int, i64>> f(n);
    vector<i64> ans(n - 1);
    const auto dfs = [&](auto&& self, int u, int fa, int id) -> void {
        auto& cur = f[u];
        cur[c[u]]++;
        if (id != -1) {
            ans[id] += t[c[u]] - 1;
        }
        for (const auto& [v, i] : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u, i);
            if (f[v].size() > cur.size()) {
                swap(f[v], cur);
            }
            if (id != -1) {
                ans[id] += ans[i];
            }
            for (const auto& [k, v] : f[v]) {
                if (id != -1) {
                    ans[id] -= 2LL * v * cur[k];
                }
                cur[k] += v;
            }
        }
    };
    dfs(dfs, 0, 0, -1);

    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << "\n";
    }
}

// ~ JustJie