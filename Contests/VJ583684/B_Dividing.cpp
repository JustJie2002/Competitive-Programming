/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.10.2023 21:05:07
****************************************************************************************************/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 6, MAX_DP = 2e5;
int a[MAX_N + 1];
bool dp[MAX_DP];

bool scan() {
    int ma = 0;
    for (int i = 1; i <= MAX_N; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    return ma != 0;
}

bool work() {
    int tot = 0;
    for (int i = 1; i <= MAX_N; i++) {
        tot += i * a[i];
    }

    if (tot & 1) {
        return false;
    }

    memset(dp, false, sizeof(dp));
    
    int desire = tot / 2;
    vector<int> ord;
    for (int i = 1; i <= MAX_N; i++) {
        int sum = i * a[i];
        for (int pw2 = 0; ; pw2++) {
            int f = (1 << pw2);
            if (i * f <= sum) {
                ord.push_back(i * f);
                sum -= i * f;
            } else {
                break;
            }
        }
        if (sum) {
            ord.push_back(sum);
        }
    }

    dp[0] = true;
    for (int x : ord) {
        for (int i = desire - x; i >= 0; i--) {
            dp[i + x] |= dp[i];
        }
    }

    return dp[desire];
}

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    for (int t = 1; scan(); t++) {
        cout << "Collection #" << t << ":\n";
        cout << (work() ? "Can be divided." : "Can't be divided.") << "\n\n";
    }
}

// ~ Jie ♥ Jenney