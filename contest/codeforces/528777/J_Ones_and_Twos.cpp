/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 13:42:47
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

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

void work(int tc) {
    int n, Q;
    cin >> n >> Q;

    vector<int> a(n);
    cin >> a;

    int sum = accumulate(a.begin(), a.end(), 0);

    set<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            pos.insert(i);
        }
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            if (x > sum) {
                cout << "NO\n";
                continue;
            }

            if (pos.empty()) {
                if (x & 1) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                }
                continue;
            }

            int i = *pos.begin();
            int j = *pos.rbegin();
            if (sum - 2 * i >= x) {
                cout << "YES\n";
                continue;
            }
            if (sum - 2 * (n - j - 1) >= x) {
                cout << "YES\n";
                continue;
            }
            
            cout << ((x & 1) == (sum & 1) ? "YES" : "NO") << "\n";
        } else if (op == 2) {
            int x, v;
            cin >> x >> v;
            x--;
            if (a[x] == v) {
                continue;
            }
            if (a[x] == 1) {
                pos.erase(x);
            } else {
                pos.insert(x);
            }
            sum -= a[x];
            a[x] = v;
            sum += a[x];
        } else assert(false);
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