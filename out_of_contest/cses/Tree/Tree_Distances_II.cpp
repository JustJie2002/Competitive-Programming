/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.17.2024 20:47:39
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

namespace reader {
template<typename T> vector<T>& operator--(vector<T> &a) { for (auto& x : a) x--; return a; }
template<typename T> vector<T>& operator++(vector<T> &a) { for (auto& x : a) x++; return a; }
template<typename T> istream& operator>>(istream& is, vector<T> &a) { for (auto& x : a) is >> x; return is;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& a) { for (int x : a) os << x << " "; return os; }
template<typename T, typename U> pair<T, U>& operator--(pair<T, U>& p) { p.first--; p.second--; return p; }
template<typename T, typename U> pair<T, U>& operator++(pair<T, U>& p) { p.first++; p.second++; return p; }
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){ is >> p.first >> p.second; return is; }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.first << " " << p.second; return os; }
};
using namespace reader;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Info = pair<int, i64>; // [cnt, tot]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<i64> ans(n);
    vector<Info> down(n);
    y_combinator(
        [&](auto&& dfs, int cur, int fa) -> Info {
            auto& info = down[cur];
            for (int nei : adj[cur]) if (nei != fa) {
                const auto& nex = dfs(nei, cur);
                info.first += nex.first + 1;
                info.second += (nex.second + nex.first + 1);
            }
            ans[cur] = info.second;
            return info;
        }
    )(0, 0);

    const Info& BASE = pair(0, 0);
    dbg(down);
    y_combinator(
        [&](auto&& dfs, int cur, int fa, const Info& bef) -> void {
            dbg(cur, ans[cur], bef);
            ans[cur] += bef.second;
            const Info& info = down[cur];
            for (int nei : adj[cur]) if (nei != fa) {
                Info nex;
                nex.first = bef.first + (info.first - down[nei].first);
                nex.second = bef.second + nex.first + (info.second - down[nei].second - 1);
                dfs(nei, cur, nex);
            }
        }
    )(0, 0, BASE);

    cout << ans << "\n";
}

// ~ Just Jie