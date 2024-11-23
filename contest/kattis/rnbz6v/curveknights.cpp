/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.28.2024 23:04:46
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    cin >> a;

    vector<vector<Edge>> adj(n);
    vector<int> deg(n);
    for (int e = 0; e < m; e++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].push_back({u, w});
        deg[u]++;
    }

    vector<i64> ans(a.begin(), a.end());

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto& [nei, w] : adj[cur]) {
            ans[nei] += ans[cur] * w;
            if (--deg[nei] == 0) {
                q.push(nei);
            }
        }
    }

    cout << ans << "\n";
}

// ~ Just Jie