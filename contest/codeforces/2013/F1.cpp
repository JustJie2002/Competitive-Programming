/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.20.2024 12:11:09
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int e = 0; e < n - 1; e++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int a, b;
    cin >> a >> b;
    a--, b--;

    vector<int> dep(n), par(n);
    const auto dfs = [&](auto&& self, int u, int p) -> void {
        par[u] = p;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dep[v] = dep[u] + 1;
        }
    };
    dfs(dfs, 0, 0);

    vector<int> res;
    if (a == b) {
        res.push_back(a);
    } else {
        vector<int> a_side, b_side;
        a_side.push_back(a);
        b_side.push_back(b);
        while (a != b) {
            if (dep[a] > dep[b]) {
                a = par[a];
                a_side.push_back(a);
            } else {
                b = par[b];
                b_side.push_back(b);
            }
        }
        ranges::reverse(b_side);
        for (int x : b_side) {
            a_side.push_back(x);
        }
        res = move(a_side);
    }

    for (int i : res) {
        if (dep[i] & 1) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ JustJie