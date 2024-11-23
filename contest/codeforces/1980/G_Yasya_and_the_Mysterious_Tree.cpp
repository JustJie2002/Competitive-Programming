/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.03.2024 20:42:55
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Edge = pair<int, int>;

constexpr int SIZE = 2;
const char MIN_CHAR = 'a';
struct Trie {
    struct Info {
        Info* nex[SIZE];
        int cnt = 0;
        void update(int v) {
            cnt += v;
        }
        bool poss(int pos) {
            return nex[pos] ? true : false;
        }
        Info* move(int pos) {
            assert(0 <= pos && pos < SIZE);
            return nex[pos];
        }
        Info* norm(int pos) {
            assert(0 <= pos && pos < SIZE);
            if (!poss(pos))
                nex[pos] = new Info();
            return nex[pos];
        }
    };

    Info* root = NULL;
    Trie() { root = new Info(); }
    constexpr int has(int mask, int nth) { return (mask >> nth) & 1; }

    void add(int mask, int tot) {
        Info* ptr = root;
        ptr->update(tot);
        for (int b = 29; b >= 0; b--) {
            int o = has(mask, b);
            ptr = ptr->norm(o);
            ptr->update(tot);
        }
    }

    int query(int mask) {
        Info* ptr = root;
        if (ptr->cnt == 0) {
            return 0;
        }
        int ans = 0;
        for (int b = 29; b >= 0; b--) {
            int o = has(mask, b) ^ 1;
            if (ptr->poss(o) && ptr->move(o)->cnt > 0) {
                ans |= (1 << b);
            } else {
                o ^= 1;
            }
            ptr = ptr->move(o);
        }
        return ans;
    }
};

void work(int tc) {
    int n, q;
    cin >> n >> q;

    vector<vector<Edge>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> v(n), d(n);
    y_combinator([&](auto &&dfs, int cur, int fa) -> void {
        for (auto [nei, w] : adj[cur]) {
            if (nei != fa) {
                v[nei] = v[cur] ^ w;
                d[nei] = d[cur] ^ 1;
                dfs(nei, cur);
            }
        }
    })(0, 0);

    vector<Trie> t(2);
    for (int i = 0; i < n; i++) {
        t[d[i]].add(v[i], 1);
    }

    int x = 0;
    while (q--) {
        char op;
        cin >> op;

        if (op == '^') {
            int w;
            cin >> w;
            x ^= w;
        } else {
            int u, w;
            cin >> u >> w;
            u--;
            int o = d[u];
            t[o].add(v[u], -1);
            int ans = max(
                t[o].query(v[u] ^ w),
                t[o ^ 1].query(v[u] ^ w ^ x)
            );
            t[o].add(v[u], 1);
            cout << ans << " \n"[q == 0];
        }
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