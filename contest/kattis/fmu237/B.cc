/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 14:36:29
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

mt19937 rng;

int brute_force(int n, int c, const vector<int>& w) {
    int ans = c;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cur = 0;
        int v = c + 1;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                cur += w[i];
            } else {
                v = min(v, w[i]);
            }
        }
        if (cur <= c && cur + v > c) {
            ans = min(ans, cur);
        }
    }
    return ans;
}

void work() {
    int n, c;
    n = 20;
    c = int(1e6) + 5;
    // cin >> n >> c;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        // cin >> w[i];
        w[i] = rng() % (c + 1);
    }

    int good = brute_force(n, c, w);

    vector<int> dp(c + 1);
    int v = c + 2;
    vector<int> f(c + 1, 1);
    dp[0] = 1;
    for (int x : w) {
        int new_v = c + 2;
        for (int i = c - x; i >= 0; i--) {
            if (dp[i] == 1) {
                dp[i + x] = 1;
                if (i + x == good) {
                    cout << "DEBUG\n";
                    cout << x << "\n";
                    cout << v << "\n";
                    cout << good + v << "\n";
                }
                new_v = min(new_v, i + x);
                f[i] = 0;
                if (v + (i + x) <= c) {
                    f[i + x] = 0;
                }
            }
        }
        v = min(v, new_v);
    }

    for (int i = 1; i <= c; i++) {
        if (dp[i] && f[i]) {
            if (good != i) {
                assert(dp[good]);
                cout << good << " " << i << "\n";
                cout << n << "\n";
                cout << c << "\n";
                for (int x : w) {
                    cout << x << " ";
                }
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie