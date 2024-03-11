/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.25.2023 22:50:31
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

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

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    map<int, set<int>> div;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        int cu = c[u], cv = c[v];
        if (cu != cv) {
            div[cu].insert(cv);
            div[cv].insert(cu);
        }
    }

    int ans = 0, color = *min_element(c.begin(), c.end());
    for (auto &[k, v] : div) {
        int res = v.size();
        if (res > ans) {
            ans = res;
            color = k;
        }
    }

    printf("%d\n", color);
}

// ~ Jie ♥ Jenney