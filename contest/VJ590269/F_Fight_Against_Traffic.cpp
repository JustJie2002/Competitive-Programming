/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.25.2023 23:39:32
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;
using Edge = pair<int, int>;

constexpr int inf = 1e9 + 5;

int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    s--, t--;

    vector<vector<int>> adj(n);
    vector<vector<int>> dense(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dense[u][v] = dense[v][u] = 1;
    }

    auto dij = [&](int source) -> vector<int> {
        vector<int> dis(n, inf);
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

        auto append = [&](int u, int w) -> void {
            if (dis[u] > w) {
                dis[u] = w;
                pq.emplace(w, u);
            }
        };

        append(source, 0);
        while (!pq.empty()) {
            auto [w, cur] = pq.top();
            pq.pop();

            if (w != dis[cur]) {
                continue;
            }

            for (int nei : adj[cur]) {
                append(nei, w + 1);
            }
        }

        return dis;
    };

    auto a = dij(s);
    auto b = dij(t);
    int pivot = a[t];

    int ans = 0;
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) if (!dense[u][v]) {
            int min_dist = min(
                a[u] + b[v] + 1,
                a[v] + b[u] + 1
            );
            if (min_dist >= pivot) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
}

// ~ Jie ♥ Jenney