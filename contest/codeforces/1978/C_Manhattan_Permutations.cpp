/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.16.2024 17:12:05
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

void report(bool result) {
    cout << (result ? "YES" : "NO") << "\n";
}

void work(int tc) {
    int n;
    i64 k;
    cin >> n >> k;

    if (k & 1) {
        report(false);
        return;
    }

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);

    i64 res = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (res + 2 * (perm[r] - perm[l]) <= k) {
            res += 2 * (perm[r] - perm[l]);
            swap(perm[l], perm[r]);
            l++;
            r--;
        } else {
            l++;
        }
    }

    if (res == k) {
        report(true);
        cout << perm << "\n";
    } else {
        report(false);
    }
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