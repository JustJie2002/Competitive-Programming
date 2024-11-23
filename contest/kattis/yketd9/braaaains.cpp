/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.06.2024 19:12:57
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
using Info = array<int, 2>;

constexpr int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<i64> q(m);
    cin >> a >> q;

    int mi = *min_element(a.begin(), a.end());

    priority_queue<Info, vector<Info>, greater<Info>> pq;
    vector<int> dis(mi, inf);
    vector<bool> used(mi);
    dis[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [w, x] = pq.top();
        pq.pop();

        if (dis[x] != w && used[x]) {
            continue;
        }
        used[x] = true;

        for (int y : a) {
            int r = x + y;
            r %= mi;
            if (w + y < dis[r]) {
                dis[r] = w + y;
                pq.push({dis[r], r});
            }
        }
    }

    vector<int> ans(m);
    int i = 0;
    for (i64 x : q) {
        int w = x % mi;
        if (dis[w] == inf) {
        } else if (dis[w] > x) {
        } else {
            ans[i] = 1;
        }
        i++;
    }
    cout << ans << "\n";
}

// ~ Just Jie