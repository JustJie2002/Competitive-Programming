/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.19.2023 02:37:47
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

using Point = pair<int, int>;

#define x   first
#define y   second

struct two_sat {
    int n;
    vector<vector<int>> adj;
    stack<int> stk;
    vector<bool> vis;

    two_sat() {}

    two_sat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        adj.clear();
        adj.assign(2 * n, vector<int>());
        vis.resize(2 * n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        int x = 2 * i + f;
        int y = 2 * j + g;
        add_edge(x ^ 1, y);
        add_edge(y ^ 1, x);
    }

    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        int x = 2 * i + f;
        int y = 2 * j + g;
        add_edge(x, y);
    }

    bool dfs(int u) {
        if (vis[u ^ 1]) {
            return false;
        }
        if (vis[u]) {
            return true;
        }

        vis[u] = true;
        stk.push(u);

        for (int v: adj[u]) {
            if (!dfs(v)) {
                return false;
            }
        }
        return true;
    }

    // Returns true if the given proposition is satisfiable and constructs a valid assignment
    bool work() {
        fill(vis.begin(), vis.end(), false);

        for (int i = 0;i < 2 * n; i += 2) {
            if (!vis[i] && !vis[i + 1]) {
                if (!dfs(i)) {
                    while (!stk.empty()) {
                        vis[stk.top()] = false;
                        stk.pop();
                    }

                    if (!dfs(i + 1)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

int main() {
    int n, r, m;
    scanf("%d%d%d", &n, &r, &m);

    vector<Point> p(m);
    two_sat tsat(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        for (int j = 0; j < i; j++) {
            { // both hor
                if (p[i].y == p[j].y) {
                    int a = min(p[i].x, p[j].x), b = max(p[i].x, p[j].x);
                    if (a + r >= b - r) {
                        tsat.add_clause_or(i, 1, j, 1);
                        tsat.add_clause_or(j, 1, i, 1);
                    }
                }
            }
            { // both ver
                if (p[i].x == p[j].x) {
                    int a = min(p[i].y, p[j].y), b = max(p[i].y, p[j].y);
                    if (a + r >= b - r) {
                        tsat.add_clause_or(i, 0, j, 0);
                        tsat.add_clause_or(j, 0, i, 0);
                    }
                }
            }
        }
    }

    puts(tsat.work() ? "1" : "0");
}