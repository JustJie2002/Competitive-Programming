/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.06.2024 02:14:50
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
    int n, m, Q;
    cin >> n >> m >> Q;

    vector<int> a(n);
    cin >> a;

    vector<int> b(m);
    cin >> b;

    set<int> seen;
    int i = 0;
    for (int x : b) {
        if (seen.count(x)) {
            continue;
        } else {
            if (i < n) {
                seen.insert(a[i++]);
            }
            if (!seen.count(x)) {
                cout << "TIDAK\n";
                return;
            }
        }
    }

    cout << "YA\n";
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