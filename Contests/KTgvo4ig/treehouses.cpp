/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 07:09:11
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
using db = double;
using Point = pair<db, db>;

#define x   first
#define y   second

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
    db w;
    Edge() {}
    Edge(int u, int v, db w): u(u), v(v), w(w) {}
    bool operator<(const Edge& e) {
        return w < e.w;
    }
};

int main() {
    int n, e, p;
    scanf("%d%d%d", &n, &e, &p);

    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &a[i].x, &a[i].y);
    }

    DSU uf(n);
    for (int _ = 0; _ < p; _++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        uf.merge(u, v);
    }

    for (int i = 0; i < e - 1; i++) {
        uf.merge(i, i + 1);
    }

    auto get_dis = [&](int i, int j) -> db {
        return sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2));
    };

    vector<Edge> edges;
    edges.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.emplace_back(i, j, get_dis(i, j));
        }
    }


    sort(edges.begin(), edges.end());

    db ans = 0;
    for (const auto& edge : edges) {
        int u = edge.u, v = edge.v;
        db w = edge.w;
        if (uf.merge(u, v)) {
            ans += w;
        }
    }

    printf("%0.4lf\n", ans);
}