/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.06.2024 02:07:34
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

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
    int n, add;
    cin >> n >> add;

    map<i64, int> f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }

    int mex = 0;
    for (const auto& [k, v] : f) {
        if (mex == k) {
            mex++;
        } else {
            break;
        }
        if (v - 1 > 0) {
            f[k + add] += v - 1;
        }
    }

    cout << mex << "\n";
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