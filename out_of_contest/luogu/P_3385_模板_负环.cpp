/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 00:09:48
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

constexpr int inf = 1e9 + 5;

using Edge = tuple<int, int, int>;

void workout(int tc) {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<Edge> edges;
    for (int e = 0; e < m; e++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        edges.push_back({u, v, w});
        if (w >= 0) {
            edges.push_back({v, u, w});
        }
    }

    // Bellman Ford Algorithm
    vector<int> dis(n, inf);
    dis[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (const auto& [u, v, w] : edges) {
            if (dis[u] != inf && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }

    bool detected = false;
    for (const auto& [u, v, w] : edges) {
        if (dis[u] != inf && dis[v] > dis[u] + w) {
            detected = true;
            break;
        }
    }

    puts(detected ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}