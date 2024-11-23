/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 20:59:01
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
using Pos = array<i64, 2>;

constexpr i64 inf = 1e18 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, K;
    cin >> n >> K;

    vector aa(n, vector<i64>(n));
    cin >> aa;

    map<i64, vector<Pos>> pos;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            pos[aa[x][y]].push_back({x, y});
        }
    }

    if (pos.size() != K) {
        cout << "-1\n";
        return 0;
    }

    set<Pos> xs, ys;
    vector dis(n, vector<i64>(n, inf));
    for (const auto &[k, v] : pos) {
        if (k != 1) {
            for (const auto &[x, y] : v) {
                i64 res = inf;
                { // check x
                    auto it = xs.lower_bound({x, 0LL});
                    if (it != xs.end()) {
                        res = min(res, (*it)[1] + ((*it)[0] - x) * ((*it)[0] - x));
                    }
                    if (it != xs.begin()) {
                        it = prev(it);
                        res = min(res, (*it)[1] + ((*it)[0] - x) * ((*it)[0] - x));
                    }
                }
                { // check y
                    auto it = ys.lower_bound({y, 0LL});
                    if (it != ys.end()) {
                        res = min(res, (*it)[1] + ((*it)[0] - y) * ((*it)[0] - y));
                    }
                    if (it != ys.begin()) {
                        it = prev(it);
                        res = min(res, (*it)[1] + ((*it)[0] - y) * ((*it)[0] - y));
                    }
                }
                dis[x][y] = res;
            }
        } else {
            for (const auto &[x, y] : v) {
                dis[x][y] = 0;
            }
        }
        xs.clear();
        ys.clear();
        for (const auto &[x, y] : v) {
            {
                auto it = xs.lower_bound({x, 0});
                if (it != xs.end() && (*it)[0] == x) {
                    if ((*it)[1] > dis[x][y]) {
                        xs.erase(it);
                        xs.insert({x, dis[x][y]});
                    }
                } else {
                    xs.insert({x, dis[x][y]});
                }
            }
            {
                auto it = ys.lower_bound({y, 0});
                if (it != ys.end() && (*it)[0] == y) {
                    if ((*it)[1] > dis[x][y]) {
                        ys.erase(it);
                        ys.insert({y, dis[x][y]});
                    }
                } else {
                    ys.insert({y, dis[x][y]});
                }
            }
        }
    }

    i64 ans = inf;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (aa[x][y] == K) {
                ans = min(ans, dis[x][y]);
            }
        }
    }

    cout << ans << "\n";
}

// ~ Just Jie