/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.04.2024 00:36:15
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    vector<int> dp(m + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = m - a[i]; j >= 0; j--) {
            if (dp[j] != -1) {
                dp[j + a[i]] = max(dp[j + a[i]], dp[j] + b[i]);
            }
        }
    }

    int ans = *max_element(dp.begin(), dp.end());
    printf("%d\n", ans);
}

// ~ Just Jie