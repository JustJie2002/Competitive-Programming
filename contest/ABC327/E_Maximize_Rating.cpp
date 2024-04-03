/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.05.2023 07:40:19
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

constexpr int N = 5001;
double dp[N][N], f[N][N];
double pw[N];

void Init() {
    pw[0] = 1.0;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 0.9;
    }
}

int main() {
    Init();
    int n;
    scanf("%d", &n);

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i][j], f[i - 1][j - 1] * .9 + p[i - 1]);
            f[i][j] = max(f[i - 1][j], f[i][j]);
        }
    }

    double ans = -1e18;
    for (int k = 1; k <= n; k++) {
        double res = -1e18;
        for (int i = 1; i <= n; i++) {
            res = max(res, f[i][k]);
        }
        double ret = 0;
        for (int i = 1; i <= k; i++) {
            res += pw[k - i];
        }
        res /= ret;
        res -= 1200. / sqrtl(1. * k);
        ans = max(ans, res);
    }

    printf("%.6lf\n", ans);
}

// ~ Jie ♥ Jenney