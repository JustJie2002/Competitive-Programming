/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 20:52:11
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> s(n);
    cin >> s;

    vector<array<int, 2>> cnt(k);
    for (int i = 0; i < k; i++) {
        cnt[i] = {};
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (s[i][j] == 'X') {
                continue;
            }
            cnt[j][s[i][j] == 'F']++;
        }
    }

    string ans;
    for (int i = 0; i < k; i++) {
        if (min(cnt[i][0], cnt[i][1]) > 1) {
            cout << "-1\n";
            return 0;
        }
        if (cnt[i][0] <= 1) {
            ans += "F";
        } else {
            ans += "T";
        }
    }
    cout << ans << "\n";
}

// ~ Just Jie