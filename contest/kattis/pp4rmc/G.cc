/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:37:22
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU uf(n);
    for (int e = 0; e < m; e++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uf.merge(u, v);
    }

    if (uf.size(0) == n) {
        cout << "Connected\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (!uf.same(i, 0)) {
                cout << i + 1 << "\n";
            }
        }
    }
}

// ~ JustJie