/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.15.2024 03:41:54
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using State = array<int, 5>;

constexpr int N = 5;
const string S = "narek";

constexpr int inf = int(1e8) + 5;
constexpr State INIT = {-inf, -inf, -inf, -inf, -inf};

void work(int tc) {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    const auto ord = [&](char c) -> int {
        auto it = S.find(c);
        if (it == string::npos) {
            return -1;
        }
        return it;
    };

    vector<State> dp(n + 1, INIT);
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        State best = INIT;
        for (int j = 0; j < i; j++) {
            for (int e = 0; e < N; e++) {
                best[e] = max(best[e], dp[j][e]);
            }
        }
        for (int e = 0; e < N; e++) {
            int cur = e;
            int score = 0;
            for (char c : s[i - 1]) {
                int o = ord(c);
                if (o == -1) {
                    continue;
                }
                if (cur == o) {
                    cur++;
                } else {
                    score--;
                }
                if (cur == N) {
                    score += 5;
                    cur = 0;
                }
            }
            dp[i][cur] = max(dp[i][cur], best[e] + score);
            ans = max(ans, dp[i][cur] - cur);
        }
    }

    cout << ans << "\n";
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

// ~ JustJie