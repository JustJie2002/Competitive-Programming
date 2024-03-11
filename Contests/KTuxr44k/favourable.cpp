/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.21.2023 14:56:17
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

constexpr int N = 401;

void workout(int tc) {
    // so much to read wtf
    int Q;
    scanf("%d", &Q);

    vector<vector<int>> adj(N);
    vector<string> comment(N);

    for (int i = 0; i < Q; i++) {
        int p;
        scanf("%d", &p);
        p--;

        auto s = nxt();
        if (s == "favourably" || s == "catastrophically") {
            comment[p] = s;
        } else {
            int a = stoi(s), b, c;
            scanf("%d%d", &b, &c);
            a--, b--, c--;
            adj[p].push_back(a);
            adj[p].push_back(b);
            adj[p].push_back(c);
        }
    }

    vector<i64> f(N, -1);
    function<i64(int)> dfs = [&](int cur) -> i64 {
        if (f[cur] != -1) {
            return f[cur];
        }
        if (comment[cur] == "favourably") {
            return 1;
        }
        if (comment[cur] == "catastrophically") {
            return 0;
        }
        f[cur] = 0;
        for (int nei : adj[cur]) {
            f[cur] += dfs(nei);
        }
        return f[cur];
    };

    printf("%lld\n", dfs(0));
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}