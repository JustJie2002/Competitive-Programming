/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 16:03:19
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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    cin >> a;
    --a;

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] != i) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    } else {
        
        vector<int> mark(n);
        for (int i = 0; i < n; i++) {
            if (mark[i]) {
                continue;
            }

            int cur = i;
            do {
                mark[cur] = 1;
                cur = a[cur];
            } while (!mark[cur]);

            if (mark[cur] == 1) {
                int f = 0;
                int o = cur;
                do {
                    f++;
                    o = a[o];
                } while (o != cur);
                if (f != k) {
                    cout << "NO\n";
                    return;
                }
            }
            cur = i;
            do {
                mark[cur] = 2;
                cur = a[cur];
            } while (mark[cur] != 2);
        }
        cout << "YES\n";
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