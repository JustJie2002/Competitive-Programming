/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.18.2024 20:02:19
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

namespace reader {
template<typename T, typename U> pair<T, U>& operator--(pair<T, U>& p) { p.first--; p.second--; return p; }
template<typename T, typename U> pair<T, U>& operator++(pair<T, U>& p) { p.first++; p.second++; return p; }
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){ is >> p.first >> p.second; return is; }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.first << " " << p.second; return os; }
template<typename T> vector<T>& operator--(vector<T> &a) { for (auto& x : a) x--; return a; }
template<typename T> vector<T>& operator++(vector<T> &a) { for (auto& x : a) x++; return a; }
template<typename T> istream& operator>>(istream& is, vector<T> &a) { for (auto& x : a) is >> x; return is; }
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
using Info = pair<int, int>;

constexpr int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Info> a(n);
    cin >> a;

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),
        [&](int i, int j) {
            return a[i].first < a[j].first;
        });

    dbg(ord);

    vector<bool> discarded(n);
    int mi = inf;
    int cur_mi = inf;
    int siz = n;
    for (int i = n - 1; i >= 0; i--) {
        int cur = ord[i];
        int nxt = (i == n - 1 ? -1 : ord[i + 1]);
        if (i == n - 1 || a[cur].first != a[nxt].first) {
            mi = min(mi, cur_mi);
            cur_mi = inf;
        }
        cur_mi = min(cur_mi, a[cur].second);
        if (a[cur].second > mi) {
            discarded[cur] = true;
            siz--;
        }
    }

    cout << siz << "\n";
    for (int i = 0; i < n; i++) {
        if (!discarded[i]) {
            cout << i + 1 << " ";
        }
    }
}

// ~ Just Jie