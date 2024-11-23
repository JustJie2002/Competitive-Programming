/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.20.2024 13:33:37
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

// Credit: Maksim1744
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define rand rng
i64 random(i64 R) { return rng() % R; }
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

    shuffle(edges.begin(), edges.end(), rng);

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

#include <ext/pb_ds/assoc_container.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(const pair<uint64_t, uint64_t>& p) const {
        uint64_t x = p.first;
        uint64_t y = p.second;
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM) ^ splitmix64(y + FIXED_RANDOM);
    }
};
 
template <typename K, typename V, typename Hash = custom_hash>
using safe_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = custom_hash>
using safe_set = safe_map<K, __gnu_pbds::null_type, Hash>;

using Point = array<int, 2>;
using Frac = pair<uint64_t, uint64_t>;

constexpr i64 inf = i64(1e13) + 5;

void work(int tc) {
    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    auto get = [&](int i, int j) -> Frac {
        i64 rise = p[i][1] - p[j][1];
        i64 run = p[i][0] - p[j][0];

        if (run == 0) {
            rise = inf;
        } else if (rise == 0) {
            run = 0;
        } else {
            int g = gcd(run, rise);
            rise /= g;
            run /= g;
        }
        return {rise, run};
    };

    const int T = min(n, 50);
    int ans = 1;
    for (int t = 0; t < T; t++) {
        int p = random(n);
        safe_map<Frac, int> freq;
        for (int i = 0; i < n; i++) {
            if (i == p) {
                continue;
            }
            ans = max(ans, ++freq[get(p, i)] + 1);
        }
    }

    cout << "Case #" << tc << ": ";
    cout << n - ans << "\n";
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ JustJie