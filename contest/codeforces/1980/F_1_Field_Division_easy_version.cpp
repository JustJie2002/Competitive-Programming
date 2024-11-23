/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.03.2024 11:17:10
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

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Pos = array<int, 2>;

constexpr int inf = -1e9 + 5;

void work(int tc) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Pos> a(k);
    map<int, vector<int>, greater<int>> pos;
    for (int i = 0; auto &[r, c] : a) {
        cin >> r >> c;
        pos[r].push_back(i++);
    }

    i64 l_most = m + 1;
    vector<int> ans(k, 1);
    int p = n;
    i64 res = 0;
    for (auto &[r, v] : pos) {
        sort(v.begin(), v.end(),
            [&](int i, int j) {
                return a[i][1] < a[j][1];
            });
        dbg(l_most, p, r);
        res += (l_most - 1) * (p - r);
        for (int i : v) {
            dbg(i, a[i][1], l_most);
            if (l_most <= a[i][1]) {
                ans[i] = 0;
            }
            l_most = min<i64>(l_most, a[i][1]);
        }
        p = r;
    }
    res += (l_most - 1) * p;
    cout << res << "\n";
    cout << ans << "\n";
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