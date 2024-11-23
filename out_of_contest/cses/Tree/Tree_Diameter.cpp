/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.17.2024 20:28:23
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int s) {
        vector<int> dis(n, n);
        vector<int> q;
        dis[s] = 0;
        q.push_back(s);
        for (int qi = 0; qi < q.size(); qi++) {
            auto cur = q[qi];
            for (int nei : adj[cur]) {
                if (dis[nei] == n) {
                    dis[nei] = dis[cur] + 1;
                    q.push_back(nei);
                }
            }
        }
        return dis;
    };

    auto dis = bfs(0);
    auto src = int(max_element(dis.begin(), dis.end()) - dis.begin());
    auto dis2 = bfs(src);
    auto ans = *max_element(dis2.begin(), dis2.end());
    cout << ans << "\n";
}

// ~ Just Jie