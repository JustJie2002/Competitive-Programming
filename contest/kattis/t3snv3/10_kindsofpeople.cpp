/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 18:22:37
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

namespace reader {
template<typename T, typename U> pair<T, U>& operator--(pair<T, U>& p) { p.first--; p.second--; return p; }
template<typename T, typename U> pair<T, U>& operator++(pair<T, U>& p) { p.first++; p.second++; return p; }
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){ is >> p.first >> p.second; return is; }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.first << " " << p.second; return os; }
template<typename T> vector<T>& operator--(vector<T> &a) { for (auto& x : a) x--; return a; }
template<typename T> vector<T>& operator++(vector<T> &a) { for (auto& x : a) x++; return a; }
template<typename T> istream& operator>>(istream& is, vector<T> &a) { for (auto& x : a) is >> x; return is;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& a) { for (int x : a) os << x << " "; return os; }
};
using namespace reader;

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

constexpr int d[] = {-1, 0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    cin >> g;

    auto compress = [&](int r, int c) {
        return r * m + c;
    };
    auto good = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m;
    };

    vector<DSU> uf(2, DSU(n * m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + d[k];
                int nj = j + d[k + 1];
                if (good(ni, nj) && g[i][j] == g[ni][nj]) {
                    uf[g[i][j] - '0'].merge(compress(i, j), compress(ni, nj));
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int a[2], b[2];
        for (int i = 0; i < 2; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < 2; i++) {
            cin >> b[i];
            b[i]--;
        }

        int x = compress(a[0], a[1]);
        int y = compress(b[0], b[1]);
        if (g[a[0]][a[1]] == '0' && uf[0].same(x, y)) {
            cout << "binary\n";
        } else if (g[a[0]][a[1]] == '1' && uf[1].same(x, y)) {
            cout << "decimal\n";
        } else {
            cout << "neither\n";
        }
    }
}

// ~ Just Jie