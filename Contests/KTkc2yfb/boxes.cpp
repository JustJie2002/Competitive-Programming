/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 22:25:40
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

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

using i64 = long long;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> from(n);
    vector<vector<int>> adj(n);
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        scanf("%d", &from[i]);
        --from[i];
        if (from[i] != -1) {
            adj[from[i]].push_back(i);
        } else {
            roots.push_back(i);
        }
    }

    vector<int> f(n), depth(n);
    function<int(int, int)> Dfs = [&](int cur, int dep) -> int {
        f[cur] = 1;
        depth[cur] = dep;
        for (int nei : adj[cur]) {
            f[cur] += Dfs(nei, dep + 1);
        }
        return f[cur];
    };

    for (int root : roots) {
        Dfs(root, 0);
    }

    auto is_ancestor = [&](int a, int b) {
        int a_dep = depth[a];
        while (depth[b] > a_dep) {
            b = from[b];
        }
        return a == b;
    };

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int m;
        scanf("%d", &m);

        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        sort(a.begin(), a.end(), [&](int i, int j) {
            return depth[i] < depth[j];
        });

        vector<int> bad(m);
        for (int i = 0; i < m; i++) {
            if (bad[i]) {
                continue;
            }

            for (int j = i + 1; j < m; j++) {
                if (bad[j]) {
                    continue;
                }
                if (is_ancestor(a[i], a[j])) {
                    bad[j] = true;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            if (!bad[i]) {
                int v = a[i];
                res += f[v];
            }
        }

        printf("%d\n", res);
    }
}