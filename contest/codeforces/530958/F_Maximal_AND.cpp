/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.22.2024 00:59:05
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

constexpr int B = 31;

void work(int tc) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    cin >> a;

    auto has = [&](int mask, int nth) {
        return mask & (1 << nth);
    };

    int cnt[B] {};
    for (int x : a) {
        for (int b = 0; b < B; b++) {
            if (has(x, b)) {
                cnt[b]++;
            }
        }
    }

    int ans = 0;
    for (int b = B - 1; b >= 0; b--) {
        int w = n - cnt[b];
        if (k >= w) {
            k -= w;
            ans |= (1 << b);
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