/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 14:55:09
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

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

constexpr int inf = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> e(n);
    cin >> e;

    vector<int> a(m);
    cin >> a;

    auto get = [&](int d) {
        if (d <= 15) {
            return 7;
        } else if (d <= 23) {
            return 6;
        } else if (d <= 43) {
            return 4;
        } else if (d <= 102) {
            return 2;
        }
        return 0;
    };

    vector<int> f(n + 1), mx(n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            f[j + 1] = max(f[j + 1], mx[j] + get(abs(a[i] - e[j])));
        }
        for (int j = 1; j <= n; j++) {
            mx[j] = max(mx[j - 1], f[j]);
        }
    }

    cout << mx.back() << "\n";
}

// ~ JustJie