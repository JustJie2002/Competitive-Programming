/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.22.2023 12:21:55
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
    int n, Q;
    scanf("%d%d", &n, &Q);

    vector<int> fa(n, -1);
    vector<vector<int>> to(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        fa[b] = a;
    }

    vector<bool> good(n);
    for (int i = 0; i < n; i++) {
        good[i] = true;
    }
    vector<bool> opt(n);

    int ans = 0;
    for (; Q--; ) {
        int u;
        scanf("%d", &u);
        u--;
        if (good[u]) {

        } else break;
    }

    printf("%d\n", ans);
}