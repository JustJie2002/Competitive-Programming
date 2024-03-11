/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.25.2023 22:04:58
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
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> good(n), path;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);
    good[0] = 1;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        path.push_back(u + 1);
        for (int v : adj[u]) if (!good[v]) {
            good[v] = 1;
            pq.push(v);
        }
    }

    for (int x : path) {
        printf("%d ", x);
    }
}

// ~ Jie ♥ Jenney