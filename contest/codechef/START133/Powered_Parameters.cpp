/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.08.2024 19:43:08
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

namespace reader {
template<typename T> vector<T>& operator--(vector<T> &a) { for (auto& x : a) x--; return a; }
template<typename T> vector<T>& operator++(vector<T> &a) { for (auto& x : a) x++; return a; }
template<typename T> istream& operator>>(istream& is, vector<T> &a) { for (auto& x : a) is >> x; return is;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& a) { for (int x : a) os << x << " "; return os; }
template<typename T, typename U> pair<T, U>& operator--(pair<T, U>& p) { p.first--; p.second--; return p; }
template<typename T, typename U> pair<T, U>& operator++(pair<T, U>& p) { p.first++; p.second++; return p; }
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){ is >> p.first >> p.second; return is; }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.first << " " << p.second; return os; }
};
using namespace reader;

using i64 = long long;

constexpr int LIM = 1e9 + 10;

void work(int tc) {
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    vector<int> sorted(a);
    sort(sorted.begin(), sorted.end());

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x = 1;
        for (i64 j = 2; ; j++) {
            i64 v = 1;
            for (int k = 0; k < i + 1; k++) {
                v *= j;
                if (v > a[i]) {
                    break;
                }
            }
            if (v > a[i]) {
                break;
            }
            x++;
        }
        ans += int(upper_bound(sorted.begin(), sorted.end(), x) - sorted.begin());
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