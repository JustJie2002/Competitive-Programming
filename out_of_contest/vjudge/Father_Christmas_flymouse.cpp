/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.18.2024 00:29:35
****************************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <stdio.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

typedef long long i64;

// Credit: Neal Wu
struct SCC {
    int V;
    vector<vector<int> > adj;
    vector<int> tour_index, low_link;
    int tour;

    vector<int> stack;
    vector<bool> in_stack;

    vector<vector<int> > components;
    vector<int> which_component;

    SCC(int v = 0) {
        init(v);
    }

    SCC(const vector<vector<int> > &_adj) {
        init(_adj);
    }

    void init(int v) {
        V = v;
        adj.assign(V, vector<int>());
    }

    void init(const vector<vector<int> > &_adj) {
        adj = _adj;
        V = int(adj.size());
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }

    // Tarjan's algorithm.
    void dfs(int node) {
        tour_index[node] = tour++;
        low_link[node] = tour_index[node];
        stack.push_back(node);
        in_stack[node] = true;

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (tour_index[neighbor] < 0) {
                // neighbor is part of our subtree.
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (in_stack[neighbor]) {
                // neighbor is a candidate for low_link.
                low_link[node] = min(low_link[node], tour_index[neighbor]);
            }
        }

        if (low_link[node] == tour_index[node]) {
            // node is the highest node in an SCC, which includes everything on the stack up to it.
            components.push_back(vector<int>());
            vector<int> &component = components.back();
            int x;

            do {
                assert(!stack.empty());
                x = stack.back();
                stack.pop_back();
                in_stack[x] = false;
                which_component[x] = int(components.size()) - 1;
                component.push_back(x);
            } while (x != node);
        }
    }

    void make() {
        tour_index.assign(V, -1);
        low_link.resize(V);
        which_component.assign(V, -1);

        stack.clear();
        stack.reserve(V);
        in_stack.assign(V, false);
        tour = 0;

        // Note that Tarjan's algorithm provides the SCCs in reverse topological order.
        components.clear();

        for (int i = 0; i < V; i++) {
            if (tour_index[i] < 0) {
                dfs(i);
            }
        }
    }
};

const int N = 30000;
i64 dp[N];
i64 res[N];

i64 dfs(int cur, const vector<vector<int> >& nadj) {
    if (dp[cur] != -1) {
        return dp[cur];
    }
    dp[cur] = res[cur];
    for (int i = 0; i < nadj[cur].size(); i++) {
        int nei = nadj[cur][i];
        assert(nei != cur);
        dp[cur] = max(dp[cur], dfs(nei, nadj) + res[cur]);
    }
    return dp[cur];
}

void work(int n, int m) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        dp[i] = -1;
        res[i] = 0;
        scanf("%d", &a[i]);
        a[i] = max(a[i], 0);
    }

    vector<vector<int> > adj(n);
    for (int e = 0; e < m; e++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }

    SCC scc(adj);
    scc.make();

    const vector<vector<int> >& comps = scc.components;
    const vector<int>& wc = scc.which_component;
    n = comps.size();
    vector<vector<int> > nadj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < comps[i].size(); j++) {
            int u = comps[i][j];
            res[i] += a[u];
            for (int k = 0; k < adj[u].size(); k++) {
                int v = adj[u][k];
                if (wc[u] != wc[v]) {
                    nadj[i].push_back(wc[v]);
                }
            }
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(i, nadj));
    }
    printf("%lld\n", ans);
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        work(n, m);
    }
}

// ~ Just Jie