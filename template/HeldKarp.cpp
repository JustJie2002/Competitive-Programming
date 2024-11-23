
using Info = pair<int, int>;

constexpr int inf = 1e9 + 5;
constexpr Info BASE = pair(inf, -1);

struct Held_Karp {
    vector<vector<int>> aa;

    Held_Karp() {}
    Held_Karp(const vector<vector<T>>& _aa): aa(_aa) {}

    int is_set(int mask, int nth) {
        return mask & (1 << nth);
    }

    pair<T, vector<int>> work() {
        int n = aa.size();
        const int N = 1 << n;

        vector dp(N, vector<Info>(n, BASE));
        for (int i = 1; i < n; i++) {
            dp[1 << i][i] = {aa[0][i], 0};
        }
        for (int mask = 2; mask < N; mask++) {
            for (int i = 0; i < n; i++) {
                if (is_set(mask, i) && dp[mask][i].first != inf) {
                    int new_mask = mask ^ (1 << i);
                    for (int j = 0; j < n; j++) {
                        if (j == 0 || j == i || dp[new_mask][j].first == inf) {
                            continue;
                        }
                        int res = dp[new_mask][j].first + aa[j][i];
                        auto& ans = dp[mask][i];
                        ans = min(ans, pair(res, i));
                    }
                }
            }
        }

        const int M = (1 << n) - 1;
        auto ans = BASE;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[M][i]);
        }
    }
}