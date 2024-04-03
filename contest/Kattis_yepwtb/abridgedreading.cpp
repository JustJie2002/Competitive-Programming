/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.25.2024 17:20:34
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
using Pair = pair<int, int>;

constexpr int INF = 1e9 + 5;
constexpr int N = 1001, LOG = 10;

int sparse[N][LOG];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    memset(sparse, -1, sizeof(sparse));

    vector<int> indeg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        indeg[v]++;
        adj[u].push_back(v);
        sparse[v][0] = u;
    }

    vector<int> up_to(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!indeg[i]) {
            q.push(i);
        }
    }

    for (int lg = 1; lg < LOG; lg++) {
        for (int i = 0; i < n; i++) {
            int to = sprase[i][lg - 1];
            sparse[i][lg] = sparse[to][i - 1];
        }
    }

    vector<int> res;
    vector<int> depth(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        up_to[u] += a[u];

        bool culm = true;
        for (int v : adj[u]) {
            culm = false;
            if (--indeg[v] == 0) {
                up_to[v] += up_to[u];
                q.push(v);
            }
        }

        if (culm) {
            res.push_back(u);
        }
    }

    auto lca = [&](int i, int j) -> int {
        
    };

    int o = res.size();
    int mi = INF;
    for (int i = 0; i < o; i++) {
        for (int j = i + 1; j < o; j++) {
            mi = min(mi, up_to[res[i]] + up_to[res[j]] - up_to[lca(i, j)]);
        }
    }
}

// ~ Just Jie