/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.30.2024 19:58:03
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 101;

int dp[N][N][2][2];

void work(int tc) {
    int n;
    cin >> n;

    int cnt[2] {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x & 1]++;
    }

    int even = cnt[0];
    int odd = cnt[1];

    const auto solve = [&](auto&& self, int e, int o, int par, int turn) -> int {
        auto& res = dp[e][o][par][turn];
        if (res != -1) {
            return res;
        }

        if (e == 0 && o == 0) {
            res = int(par == 0);
        } else if (turn) {
            // Bob: as long as alice lose one, then we're good
            res = 1;
            if (e) {
                res &= self(self, e - 1, o, par, false);
            }
            if (o) {
                res &= self(self, e, o - 1, par, false);
            }
        } else {
            // Alice: as long as we win one, then we're good
            res = 0;
            if (e) {
                res |= self(self, e - 1, o, par, true);
            }
            if (o) {
                res |= self(self, e, o - 1, par ^ 1, true);
            }
        }
        return res;
    };
    auto ans = solve(solve, even, odd, 0, 0);
    cout << (ans ? "Alice" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ Just Jie