/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.30.2023 02:23:39
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
using Edge = pair<int, int>;
using Pair = pair<int, int>;

#define f   first
#define s   second

constexpr int INF = 1E9 + 5;

int main() {
    int n, Q;
    scanf("%d%d", &n, &Q);

    vector<set<Edge>> adj(n);
    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].f, &a[i].s);
    }

    auto disconnect = [&](Edge e, int w) -> void {
        int u = e.f, v = e.s;
        adj[u].erase({v, w});
        adj[v].erase({u, w});
    };

    for (; Q--; ) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;

        adj[u].emplace(v, w);
        adj[v].emplace(u, w);
    }

    // TODO: asd asd asd asd
    int s; char d;
    scanf("%d %c", &s, &d);
    s--;

    Point cur = a[s];
    bool stopped = false;
    while (!stopped) {
        Point p = cur;
        int remove = INF;
        Edge res;
        while (p != cur) {
            auto [w, e] = move(p);
            if (w < remove) {
                remove = min(remove, w);
                res = e;
            }
        }
        while (p != cur) {
            auto& [w, e] = move(p);
            w -= remove;
            if (e == res) {
                remove--;
            }
        }
        disconnect(res, remove);
    }
}

// ~ Jie ♥ Jenney