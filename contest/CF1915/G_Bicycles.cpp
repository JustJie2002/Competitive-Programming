/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.28.2023 14:52:28
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
using Pair = pair<int, int>;
using State = tuple<i64, int, int>;

constexpr i64 inf = i64(1e18) + 10, N = 1001;

i64 dis[N][N];

void Init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dis[i][j] = inf;
        }
    }
}

void workout(int tc) {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<Pair>> adj(n);
    for (; m--; ) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    Init();

    priority_queue<State, vector<State>, greater<State>> pq;
    dis[0][0] = 0;
    pq.push({0, 0, int(1e9)});
    while (!pq.empty()) {
        auto [d, cur, slow] = pq.top();
        pq.pop();
        if (dis[cur][slow] != d) {
            continue;
        }
        if (dis[]) {
            pq.push({d, cur, s[cur]});
        }
        for (const auto& [nei, w] : adj[cur]) {
            if (dis[nei][slow] > d + w * slow) {
                dis[nei][slow] = d + w * slow;
                pq.push({dis[nei][slow], nei, slow});
            }
        }
    }

    return;

    i64 ans = inf;
    for (int i = 0; i < N; i++) {
        ans = min(ans, dis[n - 1][i]);
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}