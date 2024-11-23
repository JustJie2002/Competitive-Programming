/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.05.2024 21:26:18
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

    vector<int> left(n), right(n);
    left[0] = 1;
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1];
        if (a[i] - a[i - 1] <= b[i]) {
            left[i]++;
        } else {
            left[i] = 1;
        }
    }
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1];
        if (a[i + 1] - a[i] <= b[i]) {
            right[i]++;
        } else {
            right[i] = 1;
        }
    }

    bool ok = (right[0] + left[n - 1] >= n); // right left
    for (int i = 0; i < n - 1; i++) { // left right
        ok = ok || (left[i] + right[i + 1] == n);
    }
    for (int i = 0; i < n - 1; i++) { // left left
        ok = ok || (left[i] == (i + 1) && left[n - 1] >= n - i - 1);
    }
    for (int i = 1; i < n; i++) { // right right
        ok = ok || (right[i] == (n - i) && right[0] >= i);
    }

    cout << (ok ? "YES" : "NO") << "\n";
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