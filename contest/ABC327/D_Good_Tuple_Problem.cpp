/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.05.2023 07:23:23
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

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

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

using i64 = long long;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        b[i]--;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = a[i], v = b[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n, -1);
    auto bfs = [&](int u) -> bool {
        vector<int> q;
        q.push_back(u);
        color[u] = 0;
        for (int i = 0; i < q.size(); i++) {
            int cur = q[i];
            for (int nei : adj[cur]) {
                if (color[nei] != -1) {
                    if (color[nei] == color[cur]) {
                        return false;
                    }
                } else {
                    color[nei] = color[cur] ^ 1;
                    q.push_back(nei);
                }
            }
        }
        return true;
    };

    bool is_bipartite = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            is_bipartite &= bfs(i);
        }
    }

    puts(is_bipartite ? "Yes" : "No");
}

// ~ Jie ♥ Jenney