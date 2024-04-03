/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.19.2023 00:31:44
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

using i64 = long long;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n);

    function<void(int, int)> dfs = [&](int cur, int color) {
        if (vis[cur]) {
            return;
        }
        vis[cur] = true;
        if (color == 0) {
            printf("%d ", cur + 1);
        }
        for (int nei : adj[cur]) {
            dfs(nei, color ^ 1);
        }
        if (color == 1) {
            printf("%d ", cur + 1);
        }
    };

    dfs(0, 0);
}