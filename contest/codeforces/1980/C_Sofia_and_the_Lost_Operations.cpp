/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.03.2024 10:41:05
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

void work(int tc) {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    cin >> a >> b;

    int m;
    cin >> m;
    vector<int> c(m);
    cin >> c;

    map<int, int> dif;
    set<int> same;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            same.insert(a[i]);
        } else {
            dif[b[i]]++;
            d++;
        }
    }

    bool safe = false;
    for (int i = m - 1; i >= 0; i--) {
        int v = c[i];
        if (dif[v]) {
            d--;
            dif[v]--;
            safe = true;
        } else if (same.contains(v)) {
            safe = true;
        } else if (!safe) {
            cout << "NO\n";
            return;
        }
    }

    cout << (d == 0 ? "YES" : "NO") << "\n";
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