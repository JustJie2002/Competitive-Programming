
// Credit: Maksim1744
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
i64 random(i64 R) { return rand() % R; }
i64 random(i64 L, i64 R) { return L + random(R - L + 1); }

pair<int, int> gen_pair(int L, int R, bool same = true) {
    int u, v;

    do {
        u = random(L, R);
        v = random(L, R);
        if (u > v) {
            swap(u, v);
        }
    } while (u == v && !same);

    return make_pair(u, v);
}

struct DSU {
    vector<int> par, siz;
    int components;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        components = n;
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

using Edge = pair<int, int>;

vector<Edge> gen_tree(int n) {
    DSU uf(n);
    
    vector<Edge> edges;
    while (uf.components != 1) {
        auto [u, v] = gen_pair(0, n - 1, false);
        if (uf.merge(u, v)) {
            edges.emplace_back(u, v);
        }
    }

    return edges;
}

vector<Edge> gen_graph(int n, int m, bool connected = false) {
    set<Edge> has;
    vector<Edge> edges;

    if (connected) {
        edges = gen_tree(n);
        for (auto &[u, v] : edges) {
            if (u > v) {
                swap(u, v);
            }
        }
        has.insert(edges.begin(), edges.end());
    }

    while (edges.size() < m) {
        auto p = gen_pair(0, n - 1, false);
        if (!has.count(p)) {
            has.insert(p);
            edges.push_back(p);
        }
    }

    shuffle(edges.begin(), edges.end(), rand);

    for (auto &[u, v] : edges) {
        if (random(2)) {
            swap(u, v);
        }
    }

    return edges;
}

template <typename T>
vector<T> gen_array(int n, T L, T R) {
    vector<T> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = random(L, R);
    }

    return a;
}
