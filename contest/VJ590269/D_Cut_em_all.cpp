/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.25.2023 22:35:57
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;
using Info = pair<int, int>;

struct DSU {
    vector<int> par, siz;
    int components;

    DSU() {}
    DSU(int n): components(n) {
        init(n);
    }

    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        par[y] = x;
        components--;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

function<Info(int, int)> dfs;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs = [&](int cur, int fa) -> Info {
        int res = 0;
        int rem = 1;
        for (int nei : adj[cur]) if (nei != fa) {
            auto [removable, remaining] = dfs(nei, cur);
            res += removable;
            rem += remaining;
        }
        rem %= 2;
        if (rem == 0) {
            res++;
        }
        return make_pair(res, rem);
    };

    auto [ans, rem] = dfs(0, 0);
    ans--;
    if (rem == 1) {
        ans = -1;
    }
    printf("%d\n", ans);
}

// ~ Jie ♥ Jenney