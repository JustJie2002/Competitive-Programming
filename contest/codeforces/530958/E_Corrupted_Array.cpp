/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.22.2024 00:50:59
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

    vector<int> b(n + 2);
    cin >> b;

    sort(b.begin(), b.end());

    vector<i64> pre(n + 3);
    for (int i = 0; i < n + 2; i++) {
        pre[i + 1] = pre[i] + b[i];
    }

    const auto print = [&](int x, int y) {
        for (int i = 0; i < n + 2; i++) {
            if (i == x || i == y) {
                continue;
            }
            cout << b[i] << " ";
        }
        cout << "\n";
    };

    // assuming b[n + 1] is the thing
    for (int i = 0; i < n + 1; i++) {
        // assuming b[i] is the random element
        i64 L = pre[i];
        i64 R = pre[n + 1] - pre[i + 1];
        if (L + R == b.back()) {
            print(i, n + 1);
            return;
        } 
    }

    if (pre[n] == b[n]) {
        print(n, n + 1);
    } else {
        cout << -1 << "\n";
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