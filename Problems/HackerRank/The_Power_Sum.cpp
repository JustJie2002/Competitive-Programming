/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 16:24:40
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = a * a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

int main() {
    int t, pow;
    scanf("%d%d", &t, &pow);

    vector<int> dp(t + 1);
    dp[0] = 1;
    int add = 1;
    for (int i = 1; add <= t; i++, add = power(i, pow)) {
        for (int j = t - add; j >= 0; j--) {
            dp[j + add] += dp[j];
        }
    }

    printf("%d\n", dp.back());
}

// ~ Just Jie