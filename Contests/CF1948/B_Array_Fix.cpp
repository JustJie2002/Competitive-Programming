/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.15.2024 10:39:15
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

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    auto get = [&](int x) -> array<int, 2> {
        return {x / 10, x % 10};
    };

    vector<array<bool, 2>> dp(n);
    dp[0][0] = true;
    if (a[0] >= 10) {
        auto [t, o] = get(a[0]);
        dp[0][1] = (t <= o);
    }

    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            dp[i][0] = dp[i - 1][0];
        }
        if (dp[i - 1][1] && a[i - 1] >= 10) {
            auto [t, o] = get(a[i - 1]);
            dp[i][0] |= (o <= a[i]);
            if (a[i] >= 10) {
                auto [t1, o1] = get(a[i]);
                dp[i][1] = (t1 <= o1 && t1 >= o);
            }
        }
        if (a[i] >= 10) {
            auto [t, o] = get(a[i]);
            dp[i][1] |= (t <= o && t >= a[i - 1] && dp[i - 1][0]);
        }
    }

    dbg(dp);

    if (any_of(dp[n - 1].begin(), dp[n - 1].end(), [&](bool b) { return b; })) {
        puts("YES");
    } else {
        puts("NO");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie