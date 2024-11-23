/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.07.2024 23:44:21
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Info = array<int, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    string _;
    getline(cin, _);

    map<string, int> ids;
    int id = 0;
    vector<int> good;
    vector<vector<int>> adj;
    const auto get = [&](string s) {
        if (!ids.contains(s)) {
            ids[s] = ++id;
        }
        int x = ids[s];
        if (x >= good.size()) {
            good.resize(2 * x);
            adj.resize(2 * x);
        }
        return x;
    };

    const auto get_eq = [&]() {
        string eq;
        getline(cin, eq);
        eq += " ";
        vector<string> ops;
        string t;
        for (auto c : eq) {
            if (isspace(c)) {
                ops.push_back(t);
                t.clear();
            } else {
                t += c;
            }
        }
        return ops;
    };

    vector<set<int>> fulfilled;
    vector<Info> need;
    for (int e = 0; e < m; e++) {
        auto ops = get_eq();
        int n = ops.size();
        dbg(ops);
        if (n == 1) {
            int x = get(ops[0]);
            good[x] = 1;
        } else {
            int x = get(ops[n - 1]);
            need.push_back({x, int(ops[2] == "and")}); // 0 : or | 1 : and
            fulfilled.push_back(set<int>());
            for (int i = 1; i < n - 1; i += 2) {
                x = get(ops[i]);
                fulfilled.back().insert(x);
                adj[x].push_back(fulfilled.size() - 1);
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= id; i++) {
        if (good[i]) {
            q.push(i);
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans++;

        for (int v : adj[u]) {
            int x = need[v][0];
            if (good[x]) {
                continue;
            }
            if (fulfilled[v].contains(u)) {
                if (need[v][1] == 1) {
                    fulfilled[v].erase(u);
                    if (fulfilled[v].empty()) {
                        q.push(x);
                        good[x] = 1;
                    }
                } else {
                    q.push(x);
                    good[x] = 1;
                }
            }
        }
    }

    cout << ans << "\n";
}

// ~ Just Jie