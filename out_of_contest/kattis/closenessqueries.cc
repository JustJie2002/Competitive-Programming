/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.19.2024 20:25:28
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

struct DSU {
    vector<int> par, siz;
    int components;

    DSU() {}
    DSU(int n): components(n) {
        init(n);
    }

    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        par[y] = x;
        components--;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

void work() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(m);
    DSU uf(n);
    for (int e = 0; e < m; e++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        uf.merge(u, v);
    }

    int Q;
    cin >> Q;
    vector<int> d(n), f(n), mark(n);
    while (Q--) {
        int u, v;
        cin >> u >> v;
        if (!uf.same(u, v)) {
            cout << -1 << "\n";
            continue;
        }

        queue<int> q;
        q.push(u);
        q.push(v);
        d[u] = d[v] = 0;
        f[u] = 0;
        f[v] = 1;
        mark[u] = mark[v] = Q;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (mark[v] == Q && f[u] != f[v]) {
                    cout << d[u] + d[v] + 1 << "\n";
                    goto outer;
                }
                if (mark[v] != Q) {
                    d[v] = d[u] + 1;
                    mark[v] = Q;
                    f[v] = f[u];
                }
            }
        }
        outer:;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie