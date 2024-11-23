/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.18.2024 20:01:09
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n);
    for (int e = 0; e < m; e++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> f(n);
    queue<int> que;
    const auto work = [&](int t) -> void {
        while (!que.empty() && t--) {
            int sz = que.size();
            while (sz--) {
                auto u = que.front();
                que.pop();

                for (int v : adj[u]) {
                    if (!f[v]) {
                        f[v] = true;
                        que.push(v);
                    }
                }
            }
        }
    };


    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            x--;
            if (!f[x]) {
                f[x] = true;
                que.push(x);
            }
        } else if (op == 2) {
            int t;
            cin >> t;
            work(t);
        } else {
            int x;
            cin >> x;
            x--;
            cout << (f[x] ? "YES" : "NO") << "\n";
        }
    }
}

// ~ Just Jie