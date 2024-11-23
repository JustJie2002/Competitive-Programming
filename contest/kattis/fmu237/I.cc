/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 13:20:06
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int inf = int(1e9) + 5;

void work() {
    int n, k;
    cin >> n >> k;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<set<int>> common(k);
    for (int i = 0; i < n; i++) {
        set<int> cur;
        for (int a = 0; a < k; a++) {
            int o = s[i][a] - 'A';
            if (i != 0) {
                set<int> intersection;
                if (cur.size() < common[o].size()) {
                    for (int x : cur) {
                        if (common[o].contains(x)) {
                            intersection.insert(x);
                        }
                    }
                } else {
                    for (int x : common[o]) {
                        if (cur.contains(x)) {
                            intersection.insert(x);
                        }
                    }
                }
                common[o] = std::move(intersection);
            } else {
                common[o] = cur;
            }
            cur.insert(o);
        }
    }

    vector<vector<int>> adj(k);
    for (int i = 0; i < k; i++) {
        for (int x : common[i]) {
            adj[x].push_back(i);
        }
    }

    // dbg(adj);

    vector<int> dp(k, -1);

    const auto dfs = [&](auto&& self, int o) -> int {
        if (dp[o] != -1) {
            return dp[o];
        }
        dp[o] = 1;
        for (int nei : adj[o]) {
            dp[o] = max(dp[o], 1 + self(self, nei));
        }
        return dp[o];
    };

    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = max(ans, dfs(dfs, i));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie