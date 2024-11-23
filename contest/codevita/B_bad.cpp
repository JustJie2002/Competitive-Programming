/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.19.2024 02:30:57
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using Info = array<int, 2>;

constexpr int inf = int(1e9) + 5;

void work() {
    string s, t;
    int c[2];
    cin >> s >> t;
    for (int i = 0; i < 2; i++) {
        cin >> c[i];
    }

    int n = s.size();
    int m = t.size();

    auto ord = [&](char c) { return c - 'a'; };
    auto good = [&]() {
        int exist = 0;
        for (char c : t) {
            exist |= (1 << ord(c));
        }
        for (char c : s) {
            if (exist >> ord(c) & 1) {
            } else {
                return false;
            }
        }
        return true;
    };

    if (!good()) {
        cout << "Impossible\n";
        return;
    }

    vector<Info> f2(n);

    auto update = [&](int rev) { // O(NM)
        vector f(n + 1, vector<int>(m + 1));

        for (int i = n - 1; i >= 0; i--) {
            f2[i][rev] = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    f[i][j] = max(f[i][j], f[i + 1][j + 1] + 1);
                    f2[i][rev] = max(f2[i][rev], f[i][j]);
                }
            }
        }
    };

    update(0);
    reverse(t.begin(), t.end());
    update(1);

    vector<int> dp(n + 1, inf);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        auto& cur = dp[i];
        for (int j = 0; j < 2; j++) {
            int jump = f2[i][j];
            if (jump == 0) {
                continue;
            }
            cur = min(cur, dp[i + jump] + c[j]);
        }
    }

    int ans = dp[0];
    assert(ans != inf);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie