/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2023 00:06:57
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

struct Edge {
    int u, v;
    i64 w;
    Edge() {}
    Edge(int _u, int _v, i64 _w): u(_u), v(_v), w(_w) {}
    bool operator<(const Edge& o) {
        return w < o.w;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int mi = int(min_element(a.begin(), a.end()) - a.begin());

    vector<Edge> edges;
    for (int i = 0; i < n; i++) if (i != mi) {
        edges.emplace_back(mi, i, a[i] + a[mi]);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        i64 w;
        scanf("%d%d%lld", &u, &v, &w);
        u--, v--;
        edges.emplace_back(u, v, w);
    }

    sort(edges.begin(), edges.end());

    DSU uf(n);
    i64 res = 0;
    for (const auto& edge : edges) {
        if (uf.merge(edge.u, edge.v)) {
            res += edge.w;
        }
    }

    printf("%lld\n", res);
}

// ~ Jie ♥ Jenney