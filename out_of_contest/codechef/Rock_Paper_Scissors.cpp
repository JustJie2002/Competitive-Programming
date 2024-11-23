/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.18.2024 20:50:26
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    const auto encode = [&](char c) {
        if (c == 'R') {
            return 1;
        }
        if (c == 'P') {
            return 2;
        }
        return 3;
    };

    const auto decode = [&](int o) {
        return "RPS"[o];
    };

    const auto win = [&](int a, int b) {
        if ((a + 1) % 3 == b) {
            return b;
        }
        return a;
    };

    vector<array<int, 3>> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i == n - 1) {
                dp[i][j] = j;
            } else {
                dp[i][j] = 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ Just Jie