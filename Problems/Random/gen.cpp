/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 15:26:11
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand    rng

i64 random(i64 r) {
    return rand() % r;
}
i64 random(i64 l, i64 r) {
    return l + random(r - l + 1);
}

pair<int, int> gen_different_pair(int l, int r) {
    int u, v;
    do {
        u = random(l, r);
        v = random(l, r);
    } while (u == v);
    return make_pair(u, v);
}

pair<int, int> gen_pair(int l, int r, bool same = true) {
    int u, v;
    do {
        u = random(l, r);
        v = random(l, r);
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

vector<pair<int, int>> gen_tree(int n) {
    DSU uf(n);
    
    vector<pair<int, int>> edges;
    while (uf.components != 1) {
        auto [u, v] = gen_different_pair(0, n - 1);
        if (uf.merge(u, v)) {
            edges.emplace_back(u, v);
        }
    }

    return edges;
}

vector<pair<int, int>> gen_graph(int n, int m, bool connected = false) {
    set<pair<int, int>> has;
    vector<pair<int, int>> edges;

    if (connected) {
        edges = gen_tree(n);
        for (auto &[u, v] : edges) if (u > v) {
            swap(u, v);
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

    for (auto &[u, v] : edges) if (random(2)) {
        swap(u, v);
    }

    return edges;
}


template <typename T> vector<T> gen_array(int n, T l, T r) {
    vector<T> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = random(l, r);
    }

    return a;
}

int main() {
    int n = random(5, 100000);
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    shuffle(a.begin(), a.end(), rng);
    cout << n << "\n";
    for (int x : a) {
        cout << x << " ";
    }
}

// ~ Just Jie