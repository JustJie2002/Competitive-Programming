/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.20.2024 12:56:26
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

void work(int tc) {
    int n, k;
    cin >> n >> k;

    vector<i64> a(n);
    cin >> a;

    i64 ans = 0;
    i64 mi = ranges::min(a);
    if (n == 1) {
        ans += mi;
    } else {
        ans = mi * (2 * (n - 2) + 1);
    }


    // set<pair<int, int>> s;
    // for (int i = 0; i < n; i++) {
    //     s.emplace(-a[i], i);
    // }
    // i64 cur = 0;
    // for (int i = 0; i < n; i++) {
    //     if (!s.contains({-a[i], i})) {
    //         continue;
    //     }
    //     s.erase({-a[i], i});
    //     cur += a[i];
    //     if (!s.empty()) {
    //         s.erase(s.begin());
    //     }
    // }

    cout << "Case #" << tc << ": " << (ans <= k ? "YES" : "NO") << "\n";
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