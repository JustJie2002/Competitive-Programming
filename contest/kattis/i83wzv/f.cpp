/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2024 13:24:28
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 500;

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
    int n, Q;
    cin >> n >> Q;

    DSU uf(N);
    unordered_map<string, int> ids;

    auto get = [&](const string& s) {
        if (ids.contains(s)) {
            return ids[s];
        }
        ids[s] = ids.size();
        return ids[s];
    };

    vector<vector<int>> adj(N);
    vector<array<string, 2>> edges;
    for (int i = 0; i < n; i++) {
        string a, op, b;
        cin >> a >> op >> b;
        if (op == "is-a") {
            uf.merge(get(a), get(b));
        } else {
            edges.push_back({a, b});
        }
    }

    for (const auto& [a, b] : edges) {
        adj[get(a)].push_back(get(b));
    }

    for (int q = 1; q <= Q; q++) {
        string _a, op, _b;
        cin >> _a >> op >> _b;
        int a = get(_a);
        int b = get(_b);

        cout << "Query " << q << ": ";
        if (op == "is-a") {
            cout << (uf.same(a, b) ? "true" : "false") << "\n";
        } else {
            auto dfs = [&](auto&& self, int u) {
                if (u == b) {
                    return true;
                }
                for (int v : adj[u]) {
                    if (self(self, v)) {
                        return true;
                    }
                }
                return false;
            };
            cout << (dfs(dfs, a) ? "true" : "false") << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie