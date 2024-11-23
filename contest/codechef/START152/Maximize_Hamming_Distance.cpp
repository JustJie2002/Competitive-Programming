/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.18.2024 16:58:32
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

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
    int n, m;
    cin >> m >> n;

    vector<string> s(n);
    cin >> s;

    vector<Info> cnt(m);
    vector<int> f(m);
    for (int i = 0; i < m; i++) {
        cnt[i] = {};
    }
    for (const auto& b : s) {
        for (int i = 0; i < m; i++) {
            if (b[i] == '?') {
                f[i]++;
            } else {
                cnt[i][b[i] - '0']++;
            }
        }
    }

    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        while (f[i]) {
            if (cnt[i][0] < cnt[i][1]) {
                cnt[i][0]++;
            } else {
                cnt[i][1]++;
            }
            f[i]--;
        }
        ans += 1LL * cnt[i][0] * cnt[i][1];
    }
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

// ~ JustJie