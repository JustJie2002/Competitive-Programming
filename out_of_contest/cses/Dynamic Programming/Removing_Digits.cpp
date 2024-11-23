/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.04.2024 00:28:20
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

constexpr int inf = 1e9 + 5;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int x = i; x; x /= 10) {
            int d = x % 10;
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }
    printf("%d\n", dp.back());
}

// ~ Just Jie