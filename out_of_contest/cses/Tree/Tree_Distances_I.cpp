/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.17.2024 20:33:07
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

using i64 = long long;
using Info = array<int, 2>;

constexpr int LIMIT = 2;

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

    vector<int> down(n);
    y_combinator(
        [&](auto&& dfs, int cur, int fa) -> int {
            for (int nei : adj[cur]) if (nei != fa) {
                down[cur] = max(down[cur], dfs(nei, cur) + 1);
            }
            return down[cur];
        }
    )(0, 0);

    vector<int> ans(n);
    y_combinator(
        [&](auto&& dfs, int cur, int fa, int bef) -> void {
            ans[cur] = max(down[cur], bef);
            vector<Info> w;
            for (int nei : adj[cur]) if (nei != fa) {
                w.push_back({down[nei] + 1, nei});
                sort(w.rbegin(), w.rend());
                if (w.size() > 2) {
                    w.resize(LIMIT);
                }
            }
            for (int nei : adj[cur]) if (nei != fa) {
                if (w.size() == 1) {
                    dfs(nei, cur, bef + 1);
                } else {
                    if (w[0][1] != nei) {
                        dfs(nei, cur, max(bef, w[0][0]) + 1);
                    } else {
                        dfs(nei, cur, max(bef, w[1][0]) + 1);
                    }
                }
            }
        }
    )(0, 0, 0);

    cout << ans << "\n";
}

// ~ Just Jie