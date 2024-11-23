/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 02:26:56
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;


// Credit: Neal Wu
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

    // Tarjan's algorithm.
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
            // node is the highest node in an SCC, which includes everything on the stack up to it.
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

        // Note that Tarjan's algorithm provides the SCCs in reverse topological order.
        components = {};

        for (int i = 0; i < V; i++) {
            if (tour_index[i] < 0) {
                dfs(i);
            }
        }
    }
};

vector<string> gen() {
    string s;
    getline(cin, s);
    s += " ";
    string t;
    vector<string> res;
    for (char c : s) {
        if (isspace(c)) {
            res.push_back(t);
            t.clear();
        } else {
            t += c;
        }
    }
    return res;
}

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    gen();

    map<string, vector<int>> g;
    vector<string> speak(n);
    for (int i = 0; i < n; i++) {
        auto s = gen();
        auto name = s[0];
        speak[i] = s[1];
        g[speak[i]].push_back(i);
        for (int j = 2; j < int(s.size()); j++) {
            g[s[j]].push_back(i);
        }
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j : g[speak[i]]) {
            if (i == j) {
                continue;
            }
            adj[i].push_back(j);
        }
    }

    SCC scc(adj);
    scc.make();

    int mx = 0;
    for (const auto& comp : scc.components) {
        mx = max(mx, int(comp.size()));
    }

    cout << n - mx << "\n";
}

// ~ JustJie