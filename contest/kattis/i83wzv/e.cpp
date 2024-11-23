/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2024 15:11:48
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 501;
int deg1[N], deg2[N];
set<int> g1[N], g2[N], rg1[N], rg2[N];
int match1[N][N];
int match2[N][N];
set<int> matches[N], matches2[N];
int m = 0;

struct SCC {
    int V = 0;
    vector<vector<int>> adj;
    vector<int> tour_index, low_link;
    int tour;

    vector<int> stack;
    vector<bool> in_stack;

    vector<vector<int>> components;
    vector<int> which_component;

    SCC(int v = 0) {
        init(v);
    }

    SCC(const vector<vector<int>> &_adj) {
        init(_adj);
    }

    void init(int v) {
        V = v;
        adj.assign(V, {});
    }

    void init(const vector<vector<int>> &_adj) {
        adj = _adj;
        V = int(adj.size());
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }

    void dfs(int node) {
        tour_index[node] = tour++;
        low_link[node] = tour_index[node];
        stack.push_back(node);
        in_stack[node] = true;

        for (int neighbor : adj[node])
            if (tour_index[neighbor] < 0) {
                // neighbor is part of our subtree.
                dfs(neighbor);
                low_link[node] = min(low_link[node], low_link[neighbor]);
            } else if (in_stack[neighbor]) {
                // neighbor is a candidate for low_link.
                low_link[node] = min(low_link[node], tour_index[neighbor]);
            }

        if (low_link[node] == tour_index[node]) {
            components.emplace_back();
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

        components = {};

        for (int i = 0; i < V; i++) {
            if (tour_index[i] < 0) {
                dfs(i);
            }
        }
    }
} scc;

void solve1() {
    queue<int> q;
    for (int i = 0; i < m; i++) {
        match1[i][i] = 1;
        if (deg1[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int x : matches[u]) {
            match1[u][x] = 1;
        }

        for (int v : rg1[u]) {
            --deg1[v];
            matches[v].insert(u);
            for (int x : matches[u]) {
                matches[v].insert(x);
            }
            if (deg1[v] == 0) {
                q.push(v);
            }
        }
    }
}

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

void solve2() {
    for (int i = 0; i < m; i++) {
        for (int j : matches[i]) {
            for (int k : g2[j]) {
                g2[i].insert(k);
            }
        }
    }

    vector<vector<int>> adj(m);
    for (int i = 0; i < m; i++) {
        for (int j : g2[i]) {
            adj[i].push_back(j);
        }
    }
    scc.init(adj);
    scc.make();
    const auto& comp = scc.components;
    const auto& wc = scc.which_component;
    int m2 = comp.size();
    vector<set<int>> adj2(m2);
    for (int i = 0; i < m; i++) {
        for (int j : adj[i]) {
            if (wc[i] == wc[j]) {
                continue;
            }
            if (adj2[wc[j]].contains(wc[i])) {
                continue;
            }
            adj2[wc[j]].insert(wc[i]);
            deg2[wc[i]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < m2; i++) {
        match2[i][i] = 1;
        if (deg2[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int x : matches2[u]) {
            match2[u][x] = 1;
            for (int c : comp[x]) {
                for (int k : matches[c]) {
                    match2[u][wc[k]] = 1;
                }
            }
        }

        for (int v : adj2[u]) {
            --deg2[v];
            matches2[v].insert(u);
            for (int x : matches2[u]) {
                matches2[v].insert(x);
            }
            if (deg2[v] == 0) {
                q.push(v);
            }
        }
    }
}

/*
5 1

a has-a b
a is-a b
b has-a c
c is-a d
d has-a a

c has-a d
*/

void work() {
    int n, Q;
    cin >> n >> Q;

    unordered_map<string, int> ids;
    auto get = [&](const string& s) {
        if (ids.contains(s)) {
            return ids[s];
        }
        ids[s] = ids.size();
        m++;
        return ids[s];
    };

    for (int i = 0; i < n; i++) {
        string _a, op, _b;
        cin >> _a >> op >> _b;
        int a = get(_a);
        int b = get(_b);

        if (a == b) {
            continue;
        }
        
        if (op == "is-a") {
            if (g1[a].contains(b)) {
                continue;
            }
            deg1[a]++;
            g1[a].insert(b);
            rg1[b].insert(a);
        } else {
            if (g2[a].contains(b)) {
                continue;
            }
            g2[a].insert(b);
            rg2[b].insert(a);
        }
    }

    solve1();
    solve2();

    for (int q = 1; q <= Q; q++) {
        string _a, op, _b;
        cin >> _a >> op >> _b;
        int a = get(_a);
        int b = get(_b);
        
        cout << "Query " << q << ": ";
        if (op == "is-a") {
            cout << (match1[a][b] ? "true" : "false") << "\n";
        } else {
            int wca = scc.which_component[a];
            int wcb = scc.which_component[b];
            cout << (match2[wca][wcb] ? "true" : "false") << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie