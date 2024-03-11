/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 06:50:56
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
using Info = pair<int, int>;

#define L   first
#define R   second

constexpr int N = 101, inf = int(1e9) + 5;

int dp[N][N];
Info merged[N][N];

int main() {
    int n;
    scanf("%d", &n);

    vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].L, &a[i].R);
    }

    sort(a.begin(), a.end());

    auto merge = [&](const Info& x, const Info& y) -> Info {
        Info c;
        c.L = max(x.L, y.L);
        c.R = min(x.R, y.R);
        return c;
    };

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        merged[i][i] = a[i];
    }
    for (int k = 2; k <= n; k++) {
        for (int i = 0; i <= n - k; i++) {
            int t = i + k - 1;
            dp[i][t] = inf;
            Info cur = a[i];
            debug(cur);
            for (int j = i; j <= t; j++) {
                cur = merge(cur, a[j]);
                if (cur.L <= cur.R) {
                    dp[i][t] = min(dp[i][t], 1 + dp[j + 1][t]);
                } else break;
            }
            cur = a[t];
            for (int j = t; j >= i; j--) {
                cur = merge(cur, a[j]);
                if (cur.L <= cur.R) {
                    dp[i][t] = min(dp[i][t], 1 + dp[i][j - 1]);
                } else break;
            }
        }
    }

    printf("%d\n", dp[0][n - 1]);
}