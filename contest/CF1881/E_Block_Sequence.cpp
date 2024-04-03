/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.12.2023 11:05:37
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void work() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        int j = i + a[i];
        dp[i] = 1 + dp[i + 1];
        if (j < n) {
            dp[i] = min(dp[i], dp[j + 1]);
        }
    }

    cout << dp[0] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work();
    }
}

// ~ Jie ♥ Jenney