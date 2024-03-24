/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 14:39:25
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
using Info = array<int, 2>;

constexpr int inf = 1e9 + 5;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    int s, e;
    scanf("%d%d", &s, &e);
    s--, e--;

    vector<vector<Info>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> tor(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &tor[i]);
        tor[i]--;
    }

    map<Info, int> bad;
    int tt = 0;
    for (int i = 0; i < k - 1; i++) {
        int cur = tor[i];
        int nei = tor[i + 1];
        bool seen = false;
        for (const auto& [from, time] : adj[cur]) {
            if (from == nei) {
                tt += time;
                bad[{cur, nei}] = bad[{nei, cur}] = tt;
                seen = true;
            }
        }
        assert(seen);
    }

    vector<int> dis(n, inf);
    dis[s] = 0;
    priority_queue<Info, vector<Info>, greater<Info>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (d != dis[cur]) {
            continue;
        }

        for (const auto& [nei, t] : adj[cur]) {
            if (dis[nei] > d + t && (bad.find({cur, nei}) == bad.end() || d + t <= bad[{cur, nei}])) {
                dis[nei] = d + t;
                pq.push({dis[nei], nei});
            }
        }
    }

    int ans = dis[e];
    if (ans == inf) {
        ans = -1;
    }
    printf("%d\n", ans);
}

// ~ Just Jie