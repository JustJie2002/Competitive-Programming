/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.10.2023 21:29:57
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int inf = 1e9 + 5;
int n;

bool read() {
    return cin >> n;
}
bool ckmin(int& x, int y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

void work() {
    const int m = 2 * n;

    vector<int> a(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }

    vector<int> pre_sum(m + 1);
    for (int i = 0; i < m; i++) {
        pre_sum[i + 1] = pre_sum[i] + a[i];
    }

    auto get = [&](int L, int R) -> int {
        return pre_sum[R + 1] - pre_sum[L]; 
    };

    vector dp(m + 1, vector<int>(m, inf));
    vector kw(m, vector<int>(m, -1));
    for (int i = 0; i < m; i++) {
        dp[i][i] = 0;
        kw[i][i] = i;
    }
    for (int sz = 2; sz <= n; sz++) {
        for (int l = 0; l < m - sz + 1; l++) {
            int r = l + sz - 1;
            for (int m = kw[l][r - 1]; m <= kw[l + 1][r]; m++) {
                if ()
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    for (; read(); ) {
        work();
    }
}

// ~ Jie ♥ Jenney