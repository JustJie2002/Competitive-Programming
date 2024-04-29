/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.18.2024 02:56:41
****************************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <stdio.h>
#include <set>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

const int N = 1e4 + 5, inf = 1e9 + 5;
int a[N];
vector<int> adj[N];
vector<int> adj2[N];

int timer;
vector<bool> vis;
vector<int> tin, low;
set<pair<int, int> > bridges;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (int i = 0; i < adj[v].size(); i++) {
        int to = adj[v][i];
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                int a = min(v, to);
                int b = max(v, to);
                bridges.insert(make_pair(a, b));
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    bridges.clear();

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

bool is_cut(int u, int v) {
    return bridges.find(make_pair(u, v)) != bridges.end();
}

vector<int> sum;
vector<vector<int> > components;
vector<int> which_components;
void dfs2(int u) {
    sum.back() += a[u];
    vis[u] = true;
    which_components[u] = int(components.size()) - 1;
    components.back().push_back(u);
    for (int i = 0; i < adj[u].size(); i++) {
        int to = adj[u][i];
        if (vis[to]) {
            continue;
        }
        if (!is_cut(u, to)) {
            dfs2(to);
        }
    }
}

int ans, tot;
int dfs3(int u, int p = -1) {
    int res = sum[u];
    for (int i = 0; i < adj2[u].size(); i++) {
        int to = adj2[u][i];
        if (to == p) {
            continue;
        }
        int sum_down = dfs3(to, u);
        ans = min(ans, abs(2 * sum_down - tot));
        res += sum_down;
    }
    return res;
}

void work(int n, int m) {
    tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        tot += a[i];
        adj[i].clear();
        adj2[i].clear();
    }

    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_bridges(n);

    vis.assign(n, false);
    which_components.assign(n, -1);
    components.clear();
    sum.clear();
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            sum.push_back(0);
            components.push_back({});
            dfs2(i);
        }
    }

    for (int i = 0; i < n; i++) {
        int a = which_components[i];
        for (int j = 0; j < adj[i].size(); j++) {
            int to = adj[i][j];
            int b = which_components[to];
            if (is_cut(i, to)) {
                adj2[a].push_back(b);
                adj2[b].push_back(a);
            }
        }
    }

    ans = inf;
    dfs3(0);
    printf("%d\n", ans);

}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        work(n, m);
    }
}

// ~ Just Jie