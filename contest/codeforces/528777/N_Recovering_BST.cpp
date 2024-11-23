/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 14:31:50
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

constexpr int N = 700 + 10;

bitset<N> dense[N], dp[N][N];
// dense[i][j]: whether there can be an edge
// dp[L][R][root]: whether we can have a "root" at root within [L, R]
int l_good[N][N], r_good[N][N];
// l_good[L][R]: whether R + 1 can be the root of [L, R]
// r_good[L][R]: whether L - 1 can be the root of [L, R]
bool cache[N][N];
// cache[L][R]: whether we went through this or not

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<i64> a(n);
    cin >> a;

    for (int i = 0; i < n; i++) {
        dense[i].set(i);
        for (int j = i + 1; j < n; j++) {
            if (gcd(a[i], a[j]) > 1) {
                dense[i].set(j);
                dense[j].set(i);
            }
        }
    }

    auto check_right = [&](int L, int R) -> bool {
        if (L > R) {
            return true;
        }
        if (r_good[L][R] != 0) {
            return r_good[L][R] == 1;
        }
        if ((dense[L - 1] & dp[L][R]).any()) {
            r_good[L][R] = 1;
        } else {
            r_good[L][R] = -1;
        }
        return r_good[L][R] == 1;
    };
    auto check_left = [&](int L, int R) -> bool {
        if (L > R) {
            return true;
        }
        if (l_good[L][R] != 0) {
            return l_good[L][R] == 1;
        }
        if ((dense[R + 1] & dp[L][R]).any()) {
            l_good[L][R] = 1;
        } else {
            l_good[L][R] = -1;
        }
        return l_good[L][R] == 1;
    };

    const auto dac = [&](auto &&self, int L, int R) -> bool {
        if (L > R) {
            return true;
        }
        if (cache[L][R]) {
            return true;
        }
        cache[L][R] = true;
        for (int root = L; root <= R; root++) {
            self(self, L, root - 1);
            self(self, root + 1, R);
            if (check_left(L, root - 1) && check_right(root + 1, R)) {
                dp[L][R].set(root);
            }
        }
        return dp[L][R].any();
    };

    cout << (dac(dac, 0, n - 1) ? "YES" : "NO") << "\n";
}

// ~ Just Jie