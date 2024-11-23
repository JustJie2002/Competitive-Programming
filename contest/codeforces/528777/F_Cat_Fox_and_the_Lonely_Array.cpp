/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 13:15:04
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

constexpr int B = 21;

void work(int tc) {
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    auto has = [&](int mask, int nth) {
        return mask & (1 << nth);
    };

    array<int, B> lst;
    lst.fill(-1);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < B; b++) {
            if (has(a[i], b)) {
                ans = max(ans, i - lst[b]);
                lst[b] = i;
            }
        }
    }

    for (int b = 0; b < B; b++) {
        if (lst[b] != -1) {
            ans = max(ans, n - lst[b]);
        }
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

// ~ Just Jie