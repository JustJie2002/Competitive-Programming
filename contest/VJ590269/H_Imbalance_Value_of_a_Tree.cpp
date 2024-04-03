/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2023 17:14:11
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

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
    int n;
    scanf("%d", &n);

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    vector<vector<int>> edges(n);
    for (int _ = 0; _ < n - 1; _++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    auto solve = [&]() -> i64 {
        vector<int> ord(n), vis(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {
            return make_pair(w[i], i) < make_pair(w[j], j);
        });

        DSU uf(n);
        i64 res = 0;
        for (int cur : ord) {
            res += w[cur];
            i64 nodes = 1;
            for (int nei : edges[cur]) if (vis[nei]) {
                res += nodes * uf.size(nei) * w[cur];
                nodes += uf.size(nei);
                uf.merge(cur, nei);
            }
            vis[cur] = 1;
        }

        return res;
    };

    i64 ans = solve();
    for (int i = 0; i < n; i++) {
        w[i] *= -1;
    }
    ans += solve();

    printf("%lld\n", ans);
}

// ~ Jie ♥ Jenney