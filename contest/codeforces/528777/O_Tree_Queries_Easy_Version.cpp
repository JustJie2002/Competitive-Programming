/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 16:40:02
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int inf = int(1e9) + 5;

void work(int tc) {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int e = 0; e < n - 1; e++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1) {
        cout << "0\n";
        return;
    }

    const auto dfs = [&](auto &&self, int u, int p) -> int {
        int ans = 0;
        int leaves = 0;

        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            auto splits = self(self, v, u);
            if (splits == 0) {
                leaves++;
            }
            ans += splits;
        }

        return ans + max(0, leaves - 1);
    };

    int ans = inf;
    for (int root = 0; root < n; root++) {
        ans = min(ans, dfs(dfs, root, root) + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ Just Jie