/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.30.2024 19:37:59
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
using P = array<i64, 2>;

void work(int tc) {
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    vector<i64> groups;
    i64 cur = 0;
    for (int x : a) {
        if (cur == 0) {
            cur += x;
        } else if ((cur < 0) == (x < 0)) {
            cur += x;
        } else {
            groups.push_back(cur);
            cur = x;
        }
    }
    groups.push_back(cur);

    int m = groups.size();

    vector<P> dp(m);
    dp[0][0] = dp[0][1] = groups[0];
    for (int i = 1; i < m; i++) {
        i64 x = groups[i];
        dp[i][0] = dp[i - 1][0] + x;
        dp[i][1] = max({
            abs(dp[i - 1][0] + x),
            dp[i - 1][1] + x,
            abs(dp[i - 1][0]) + x,
            abs(abs(dp[i - 1][0]) + x)
        });
    }
    cout << max(abs(dp[m - 1][0]), abs(dp[m - 1][1])) << "\n";
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