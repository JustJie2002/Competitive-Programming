/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.20.2024 14:42:10
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = pair<int, int>;

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

void work(int tc) {
    int n, g;
    cin >> n >> g;

    vector<int> a(n);
    cin >> a;

    ranges::sort(a, greater<>());

    set<Info> s;
    int p = -1;
    for (int i = 0; i < n; i++) {
        if (p == a[i]) {
            continue;
        }
        s.emplace(a[i], i);
        p = a[i];
    }

    auto it = s.lower_bound({g, 0});
    int res = -1;
    if (it != s.end()) {
        res = it->second;
    }
    if (it != s.begin()) {
        it--;
        int cur = it->first;
        if (res == -1 || abs(cur - g) < abs(g - a[res])) {
            res = it->second;
        } else if (abs(cur - g) == abs(g - a[res]) && it->second < res) {
            res = it->second;
        }
    }

    cout << "Case #" << tc << ": ";
    cout << res + 1 << " " << abs(g - a[res]) << "\n";
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