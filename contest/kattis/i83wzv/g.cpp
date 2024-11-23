/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2024 13:58:34
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work() {
    int n;
    i64 m;
    cin >> n >> m;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector pre2D(n, vector(n, vector<i64>(n)));
    vector<i64> mi(n);
    mi[0] = m;
    for (int i = 1; i < n; i++) {
        mi[i] = mi[i - 1] * 2 / 3;
    }
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < n; s++) {
            i64 res = 0;
            for (int j = i; j < i + (n - s) && j < n; j++) {
                res += min(mi[j - i + s], a[j]);
                pre2D[i][s][j] = res;
            }
        }
    }

    vector dp(n + 1, vector<i64>(n + 1));
    i64 ans = 0;
    for (int i = 1; i <= n; i++) { // where are we
        for (int j = i; j <= n; j++) { // how long we are going to eat until
            for (int k = 0; k <= n; k++) { // how long we resting
                if (i - k < 0) {
                    break;
                }
                for (int l = 0; l <= n; l++) { // how long we eating before the break
                    if (k + l >= i) {
                        break;
                    }
                    int cut = max(0, l - k);
                    if (k >= 2) {
                        cut = 0;
                    }
                    i64 cur = pre2D[i - 1][cut][j - 1];
                    dp[j][cut + j - i + 1] = max(dp[j][cut + j - i + 1], dp[max(0, i - k - 1)][l] + cur);
                    ans = max(ans, dp[j][cut + j - i + 1]);
                }
            }
        }
    }

    cout << ans << "\n";
    // cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie