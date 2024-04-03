/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.15.2024 16:48:00
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
using Edge = array<int, 3>;

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

constexpr int inf = 1e9 + 5;

int main() {
    int n, c;
    scanf("%d%d", &n, &c);

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            scanf("%d", &w);
            if (w) {
                edges.push_back({i, j, w});
            }
        }
    }

    sort(edges.begin(), edges.end(), 
        [&](auto&& e1, auto&& e2) {
            return e1[2] < e2[2];
        });

    auto set_bit = [&](int msk, int b) {
        return (msk >> b) & 1;
    };

    int ans = inf;
    for (int msk = 0; msk < (1 << n); msk++) {
        DSU uf(n);
        int mst = 0;
        for (const auto& [u, v, w] : edges) {
            if ((set_bit(msk, u) ^ set_bit(msk, v)) && uf.merge(u, v)) {
                mst += w;
            }
        }
        mst += __builtin_popcount(msk) * c;
        if (uf.components == 1) {
            ans = min(ans, mst);
        }
    }

    printf("%d\n", ans);
}

// ~ Just Jie