/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.19.2023 00:27:38
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

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for (; m--; ) {
        int p, q;
        scanf("%d%d", &p, &q);
        deg[q]++;
        adj[p].push_back(q);
    }

    vector<int> path;
    path.reserve(n);

    queue<int> q;

    for (int v = 0; v < n; v++) {
        if (deg[v] == 0) {
            q.push(v);
        }
    }

    while (!q.empty()) {
        int Q = q.size();
        if (Q > 1) {
            puts("back to the lab");
            return 0;
        }

        auto cur = q.front();
        q.pop();

        path.push_back(cur);

        for (int nei : adj[cur]) {
            if (--deg[nei] == 0) {
                q.push(nei);
            }
        }
    }

    if (path.size() == n) {
        for (int i = 0; i < n; i++) {
            printf("%d%c", path[i], " \n"[i == n - 1]);
        }
    } else {
        puts("back to the lab");
    }
}