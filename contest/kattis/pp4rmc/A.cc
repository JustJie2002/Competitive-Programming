/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 02:55:53
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;
using Item = array<int, 3>;

constexpr int inf = int(1e9) + 5;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<vector<Info>> adj(n);
    for (int e = 0; e < m; e++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto dij = [&](int src) -> array<vector<int>, 2> {
        vector<int> dis(n, inf);
        vector<int> score(n);
        priority_queue<Item, vector<Item>, greater<Item>> h;
        dis[src] = 0;
        score[src] = a[src];
        h.push({0, -a[src], src});
        while (!h.empty()) {
            auto [d, s, u] = h.top();
            h.pop();

            if (d != dis[u] || -s != score[u]) {
                continue;
            }

            for (const auto& [v, w] : adj[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    score[v] = -s + a[v];
                    h.push({dis[v], -score[v], v});
                } else if (d + w == dis[v] && -s + a[v] > score[v]) {
                    score[v] = -s + a[v];
                    h.push({dis[v], -score[v], v});
                }
            }
        }
        return {dis, score};
    };

    const auto& [adis, ascore] = dij(0);
    const auto& [bdis, bscore] = dij(n - 1);
    const int D = adis[n - 1];

    if (D == inf) {
        cout << "impossible\n";
        return 0;
    }

    dbg(adis);
    dbg(bdis);
    dbg(ascore);
    dbg(bscore);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (adis[i] + bdis[i] == D) {
            ans = max(ans, ascore[i] + bscore[i] - a[i]);
        }
    }
    cout << D << " " << ans << "\n";
}

// ~ JustJie