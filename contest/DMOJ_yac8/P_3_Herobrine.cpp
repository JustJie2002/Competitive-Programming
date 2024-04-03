/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.02.2024 09:33:53
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;
using Pair = pair<int, int>;

#define f   first
#define s   second

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

vector<Pair> groupby(vector<int>& a) {
    a.push_back(a.back() + 1);
    int n = a.size();
    
    vector<Pair> res;
    int p = a[0], cnt = 0;
    for (int x : a) {
        if (p == x) {
            cnt++;
        } else {
            res.emplace_back(p, cnt);
            p = x;
            cnt = 1;
        }
    }

    return res;
}

vector<int> sub(const vector<Pair>& lhs, const vector<Pair>& rhs) {
    int m = rhs.size();
    int i = 0, j = 0;
    vector<int> res;
    while (j < m) {
        while (lhs[i].f < rhs[j].f) {
            res.push_back(lhs[i].s);
            i++;
        }
        res.push_back(lhs[i].s - rhs[j].s);
        i++, j++;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> adj(n);
    for (int to = 0; to < n; to++) {
        int par;
        scanf("%d", &par);
        par--;
        if (par != -1) {
            adj[par].push_back(to);
        }
    }

    vector<vector<Pair>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        vector<int> b(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i]);
        }
        sort(b.begin(), b.end());
        a[i] = groupby(b);
    }

    auto merge = [&](auto& cur, const auto& nei) -> void {
        int c_siz = cur.size(), n_siz = nei.size();

        vector<Pair> res;
        int i = 0, j = 0;
        while (i < c_siz && j < n_siz) {
            if (cur[i].f == nei[j].f) {
                res.emplace_back(cur[i].f, cur[i].s + nei[j].s);
                i++, j++;
            } else if (cur[i].f < nei[j].f) {
                res.push_back(cur[i]);
                i++;
            } else {
                res.push_back(nei[j]);
                j++;
            }
        }
        while (i < c_siz) {
            res.push_back(cur[i]);
            i++;
        }
        while (j < n_siz) {
            res.push_back(nei[j]);
            j++;
        }

        swap(res, cur);
    };

    y_combinator([&](auto&& dfs, int cur) -> void {
        for (int nei : adj[cur]) {
            dfs(nei);
            merge(a[cur], a[nei]);
        }
    })(0);

    auto solve = [&](const vector<int>& res) -> int {
        sort(res.begin(), res.end());
        int m = res.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, (m - i) * res[i]);
        }
        return ans;
    };

    auto norm = [&](const vector<Pair>& p) -> vector<int> {
        vector<int> res;
        for (const auto& [x, f] : p) {
            res.push_back(f);
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        int ans = min(
            solve(sub(a[0], a[i])),
            solve(norm(a[i]))
        );
        printf("%d\n", ans);
    }
}

// ~ Just Jie