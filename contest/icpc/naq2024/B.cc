/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 13:51:41
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Point = pair<double, double>;

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

constexpr double INF = 1e16;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    double ans = INF;
    for (int i = 0; i < n; i++) {
        Point a, b;
        cin >> a >> b;
        if (a.first > b.first) {
            swap(a, b);
        }

        if (a.first > 0 || b.first < 0) {
            continue;
        }

        double slope = (a.second - b.second) / (a.first - b.first);

        double y = a.second - slope * a.first;
        if (y >= 0.) {
            ans = min(ans, y);
        }
    }

    if (ans == INF) {
        cout << -1.0 << "\n";
    } else {
        cout << fixed << setprecision(5);
        cout << ans << "\n";
    }
}

// ~ JustJie