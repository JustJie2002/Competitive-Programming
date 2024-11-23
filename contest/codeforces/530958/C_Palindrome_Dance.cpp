/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.22.2024 00:15:05
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

    int n;
    cin >> n;

    int x[2];
    for (int i = 0; i < 2; i++) {
        cin >> x[i];
    }

    vector<int> a(n);
    cin >> a;

    int ans = 0;
    int f = min(x[0], x[1]);
    for (int i = 0; i < n / 2; i++) {
        bool L = (a[i] == 2);
        bool R = (a[n - i - 1] == 2);
        if (L && R) {
            ans += 2 * f;
        } else if (L || R) {
            ans += x[min(a[i], a[n - i - 1])];
        } else if (a[i] != a[n - i - 1]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    if (n & 1) {
        if (a[n / 2] == 2) {
            ans += f;
        }
    }

    cout << ans << "\n";
}

// ~ Just Jie