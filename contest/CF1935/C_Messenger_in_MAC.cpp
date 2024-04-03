/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.05.2024 09:59:48
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Info = pair<i64, i64>;
using Pair = pair<Info, int>;

constexpr int INF = 1e9 + 10;

void workout(int tc) {
    int n;
    i64 l;
    scanf("%d%lld", &n, &l);

    vector<vector<Info>> adj(n);
    vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        if (a[i].first > l) {
            continue;
        }
        for (int j = 0; j < i; j++) {
            int dif = abs(a[i].second - a[j].second);
            if (a[j].first > l) {
                continue;
            }
            if (dif > l) {
                continue;
            }
            adj[i].emplace_back(j, dif);
            adj[j].emplace_back(i, dif);
        }
    }

    auto dijkstra = [&](int u) -> int {
        vector<Info> dis(n, make_pair(INF, INF));
        priority_queue<Pair> pq;
        vector<int> vis(n);

        dis[u] = make_pair(a[u].first, 1);
        pq.push({dis[u], u});

        auto enqueue = [&](int from, int to, i64 d) -> void {
            if (d > l) {
                return;
            }
            if (dis[to].second == INF || (dis[to].second == dis[from].second + 1 && dis[to].first < d)) {
                dis[to] = make_pair(d, dis[from].second + 1);
                pq.push({dis[to], to});
                return;
            }
            if (dis[to].second == INF || dis[to].second < dis[from].second + 1) {
                dis[to] = make_pair(d, dis[from].second + 1);
                pq.push({dis[to], to});
                return;
            }
        };

        while (!pq.empty()) {
            auto [p, v] = pq.top();
            pq.pop();
            auto [d, c] = p;
            
            if (p != dis[v]) continue;
            vis[v] = 1;

            for (const auto& [nei, w] : adj[v]) {
                if (!vis[nei]) {
                    enqueue(v, nei, d + w + a[nei].first);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dis[i].second != INF) {
                ans = max<int>(ans, dis[i].second);
            }
        }
        return ans;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first <= l) {
            ans = max(ans, dijkstra(i));
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie