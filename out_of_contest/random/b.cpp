/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.19.2024 17:33:45
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

using Info = tuple<int, int, char>;

void work() {
    int n, m;
    cin >> n >> m;
    int r, b, y;
    cin >> r >> b >> y;
    r--, b--, y--;

    vector<vector<Info>> adj(n);
    for (int e = 0; e < m; e++) {
        int u, v;
        char op;
        cin >> u >> v >> op;
        u--, v--;
        adj[u].push_back({v, e, op});
        adj[v].push_back({u, e, op});
    }

    vector vis(n, vector(n, vector<bool>(n)));
    vector<int> used(m);
    const auto dfs = [&](auto&& self, int r, int b, int y) -> void {
        if (vis[r][b][y]) {
            return;
        }
        vis[r][b][y] = true;

        for (const auto& [to, e, op] : adj[r]) {
            if (op == 'R' || op == 'X') {
                used[e] = true;
                self(self, to, b, y);
            }
            if (op == 'P' && r == b) {
                used[e] = true;
                self(self, to, to, y);
            } 
            if (op == 'O' && r == y) {
                used[e] = true;
                self(self, to, b, to);
            }
        }

        for (const auto& [to, e, op] : adj[b]) {
            if (op == 'B' || op == 'X') {
                used[e] = true;
                self(self, r, to, y);
            }
            if (op == 'G' && b == y) {
                used[e] = true;
                self(self, r, to, to);
            }
        }

        for (const auto& [to, e, op] : adj[y]) {
            if (op == 'Y' || op == 'X') {
                used[e] = true;
                self(self, r, b, to);
            }
        }
    };

    dfs(dfs, r, b, y);
    for (int i = 0; i < n; i++) {
        for (const auto& [to, e, op] : adj[i]) {
            if (op == 'X') {
                continue;
            }
            if (!used[e]) {
                cout << 0 << "\n";
                return;
            }
        }
    }
    cout << 1 << "\n";
}
/*
6 6 1 6 1
1 2
2 3
3 4
4 5
2 6
4 6
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie