/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.03.2024 10:46:40
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

constexpr int inf = 1e9 + 5;

void work(int tc) {
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    vector<int> g;
    g.reserve(n + 1);
    g.push_back(0);
    for (int i = 0; i < n - 1; i++) {
        g.push_back(gcd(a[i], a[i + 1]));
    }
    g.push_back(inf);
    dbg(g);

    vector<bool> pre(n + 1), suf(n + 1);
    pre[0] = true;
    suf[n] = true;
    for (int i = 1; i < n + 1; i++) {
        pre[i] = pre[i - 1] && (g[i] >= g[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] && (g[i] <= g[i + 1]);
    }

    if (suf[2] || pre[n - 2]) {
        cout << "YES\n";
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        int gg = gcd(a[i - 1], a[i + 1]);
        dbg(i, gg, g[i - 1], g[i + 2]);
        if (pre[i - 1] && suf[i + 2] && gg >= g[i - 1] && gg <= g[i + 2]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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