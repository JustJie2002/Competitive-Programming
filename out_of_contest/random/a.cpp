/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.28.2024 20:14:07
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

constexpr int MOD = 1e9 + 7;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum & 1) {
        puts("0");
        return 0;
    }

    int w = sum / 2;
    vector<i64> dp(w + 1);
    dp[0] = 1;
    for (int x : a) {
        for (int i = w - x; i >= 0; i--) {
            dp[i + x] += dp[i];
            if (dp[i + x] >= MOD) {
                dp[i + x] -= MOD;
            }
        }
    }
    printf("%d\n", dp[w]);
}

// ~ Just Jie