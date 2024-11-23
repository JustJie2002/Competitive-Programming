/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 00:49:08
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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    cin >> a;

    int sum = accumulate(a.begin(), a.end(), 0);

    while (q--) {
        int x;
        cin >> x;

        if (x > sum) {
            cout << "No\n";
        } else if (x == sum) {
            cout << "Yes\n";
        } else if (x == 0) {
            cout << "Yes\n";
        } else {
            bool good = false;
            int cur = 0;
            x = sum - x;
            for (int l = 0, r = 0; r < n; r++) {
                cur += a[r];
                while (cur > x) {
                    cur -= a[l++];
                }
                if (cur == x) {
                    good = true;
                    break;
                }
            }
            cout << (good ? "Yes" : "No") << "\n";
        }
    }
}

// ~ Just Jie