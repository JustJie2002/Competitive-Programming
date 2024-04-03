/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.30.2023 01:18:25
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

constexpr double inf = 2e18;

int main() {
    int s, t, k;
    double r;
    scanf("%d%d%d%lf", &s, &t, &k, &r);
    r /= 2.;
    r *= r;

    int n = s + t;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    sort(a.begin(), a.end());

    vector<double> pre(n + 1), pre2(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
        pre2[i + 1] = pre2[i] + a[i] * a[i];
    }

    auto get = [&](int L, int R) -> double {
        return pre[R + 1] - pre[L];
    };
    auto get2 = [&](int L, int R) -> double {
        return pre2[R + 1] - pre2[L];
    };
    auto get_mean = [&](int L, int R) -> double {
        int sz = R - L + 1;
        return get(L, R) / (double) sz;
    };

    vector dp(n + 1, vector<double>(k + 1, inf));
    dp[0][k] = 0;
    for (int i = 0; i < n; i++) {
        for (int rem = 1; rem <= k; rem++) if (dp[i][rem] != inf) {
            for (int j = i; j < n; j++) {
                int m = j - i + 1;
                double mean = get_mean(i, j);
                double res = m * mean * mean - 2. * mean * get(i, j) + get2(i, j);
                dp[j + 1][rem - 1] = min(dp[j + 1][rem - 1], dp[i][rem] + res);
            }
        }
    }

    printf("%0.7lf\n", (double) n * r + dp[n][0]);
}

// ~ Jie ♥ Jenney