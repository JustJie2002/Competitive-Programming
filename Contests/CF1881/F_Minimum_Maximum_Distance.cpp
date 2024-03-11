/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.12.2023 11:34:00
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Info {
    int dis;
    int from;
    bool operator<(const Info& o) {
        return dis >= o.dis;
    }
};

constexpr int inf = 1e9 + 5;

void work() {
    int n, k;
    cin >> n >> k;

    vector<int> marked(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        marked[x] = true;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 1) {
        cout << 0 << "\n";
        return;
    }

    vector<vector<Info>> dp(n);

    auto norm = [&](int cur) -> void {
        sort(dp[cur].begin(), dp[cur].end());
        int m = min(2, int(dp[cur].size()));
        dp[cur].resize(m);
    };

    vector<int> f(n);
    auto dfs1 = [&](auto self, int cur, int fa) -> int {
        if (marked[cur]) {
            dp[cur].push_back({0, cur});
        }
        for (int nei : adj[cur]) if (nei != fa) {
            auto p = self(self, nei, cur);
            if (p != inf) {
                dp[cur].push_back({p, nei});
            }
            norm(cur);
        }
        int p = inf;
        if (!dp[cur].empty()) {
            p = dp[cur][0].dis + 1;
        }
        if (p != inf) {
            f[cur] = max(f[cur], p - 1);
        }
        return p;
    };
    dfs1(dfs1, 0, 0);

    auto dfs2 = [&](auto self, int cur, int fa, int d) -> void {
        if (d != inf) {
            f[cur] = max(f[cur], d);
        }

        for (int nei : adj[cur]) if (nei != fa) {
            int nex = (d == inf ? inf : d + 1);
            for (auto x : dp[cur]) {
                if (x.from != nei && (x.dis + 1 > nex || nex == inf)) {
                    nex = x.dis + 1;
                    break;
                }
            }
            self(self, nei, cur, nex);
        }
    };

    dfs2(dfs2, 0, 0, inf);

    int res = inf;
    for (int x : f) {
        res = min(res, x);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work();
    }
}

// ~ Jie ♥ Jenney