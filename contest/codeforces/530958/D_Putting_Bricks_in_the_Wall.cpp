/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.22.2024 00:34:19
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
using Pos = array<int, 2>;

constexpr int dir[] {0, -1, 0, 1, 0};

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

void work(int tc) {
    int n;
    cin >> n;

    vector<string> s(n);
    cin >> s;

    vector<Pos> cand;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            cand.push_back({i, j});
        }
    }

    for (int i = n - 2; i < n; i++) {
        for (int j = n - 2; j < n; j++) {
            if (i == n - 1 && j == n - 1) {
                continue;
            }
            cand.push_back({i, j});
        }
    }

    const auto encode = [&](int i, int j) {
        return i * n + j;
    };

    const auto good = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < n;
    };

    const int END = encode(n - 1, n - 1);
    const int N = n * n;

    const auto check = [&]() {
        DSU uf(N);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dir[d];
                    int nj = j + dir[d + 1];
                    if (good(ni, nj) && (s[i][j] == 'S' || s[ni][nj] == 'F' || s[i][j] == s[ni][nj])) {
                        uf.merge(encode(i, j), encode(ni, nj));
                    }
                }
            }
        }
        return !uf.same(0, END);
    };

    if (check()) {
        cout << 0 << "\n";
        return;
    }

    auto rev = [&](const auto &p) {
        s[p[0]][p[1]] ^= 1;
    };

    int m = cand.size();
    for (int i = 0; i < m; i++) {
        rev(cand[i]);
        if (check()) {
            cout << 1 << "\n";
            cout << cand[i][0] + 1 << " " << cand[i][1] + 1 << "\n";
            return;
        }
        for (int j = i + 1; j < m; j++) {
            rev(cand[j]);
            if (check()) {
                cout << 2 << "\n";
                cout << cand[i][0] + 1 << " " << cand[i][1] + 1 << "\n";
                cout << cand[j][0] + 1 << " " << cand[j][1] + 1 << "\n";
                return;
            }
            rev(cand[j]);
        }
        rev(cand[i]);
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ Just Jie