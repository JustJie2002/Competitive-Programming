/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 19:59:05
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

constexpr int LOG = 3;
constexpr int B = 2;

void work(int tc) {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int e = 0; e < n - 1; e++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector up(n, -1);
    vector<int> dep(n);
    const auto dfs = [&](auto &&self, int x, int f) -> void {
        for (int y : adj[x]) {
            if (y != f) {
                up[y] = x;
                dep[y] = dep[x] + 1;
                self(self, y, x);
            }
        }
    };
    dfs(dfs, 0, 0);

    vector<int> p(n);
    cin >> p;
    --p;

    const auto work = [&](int a, int b) -> bool {
        int a_dep = dep[a];
        int b_dep = dep[b];
        if (a_dep > b_dep) {
            swap(a_dep, b_dep);
            swap(a, b);
        }

        int dif = b_dep - a_dep;
        int res = dif;
        if (res > 3) {
            return false;
        }
        while (dif--) {
            b = up[b];
        }

        if (a == b) {
            return true;
        }
        a = up[a];
        b = up[b];
        res += 2;
        return a == b && res <= 3;
    };

    bool good = true;
    for (int i = 1; i < n; i++) {
        int a = p[i - 1];
        int b = p[i];
        good = good && work(a, b);
    }
    
    cout << (good ? "1" : "0") << "\n";
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