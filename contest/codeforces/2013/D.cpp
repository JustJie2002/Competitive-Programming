/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.20.2024 10:53:31
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

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

constexpr i64 inf = i64(1e15) + 5;

void work(int tc) {
    int n;
    cin >> n;

    vector<i64> a(n);
    cin >> a;

    a.push_back(inf);

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    n++;

    i64 mi = inf, ma = 0;

    const auto work = [&](int i, int j) -> void {
        int par = 0;
        i64 sum = 0;
        for (int x = i; x <= j; x++) {
            par |= 1 << (a[x] % 2);
            sum += a[x];
        }
        int siz = j - i + 1;
        i64 each = sum / siz;
        if (sum % siz == 0) {
            mi = min(mi, each);
            ma = max(ma, each);
        } else {
            mi = min(mi, each);
            ma = max(ma, each + 1);
        }
    };

    int piv = 0;
    i64 cur = a[0];
    for (int i = 1; i < n; i++) {
        if (a[piv] >= a[i] && a[i] <= (cur + a[i]) / (i - piv + 1) + int((cur + a[i]) % (i - piv + 1) != 0)) {
            cur += a[i];
        } else {
            work(piv, i - 1);
            piv = i;
            cur = a[i];
        }
    }

    cout << ma - mi << "\n";
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