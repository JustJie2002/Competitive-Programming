/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 13:36:23
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = int(1e5) + 5, D = 10;
constexpr int MOD = 998244353;

i64 f[N][D][2][2];
string s;
int n;

i64 dp(int i, int p, int is_tight, int is_leading) {
    if (f[i][p][is_tight][is_leading] != -1) {
        return f[i][p][is_tight][is_leading];
    }
    if (i == n) {
        return 1;
    }
    auto& ans = f[i][p][is_tight][is_leading];
    ans = 0;

    int curD = (is_tight ? (s[i] - '0' + 1) : D);
    for (int d = 0; d < curD; d++) {
        if (!is_leading && d == p) {
            continue;
        }
        bool tight = (is_tight && d == (s[i] - '0'));
        if (d == 0) {
            if (is_leading) {
                ans += dp(i + 1, p, false, is_leading);
            } else {
                ans += dp(i + 1, d, tight, is_leading);
            }
        } else {
            ans += dp(i + 1, d, tight, false);
        }
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    return ans;
}

i64 work(string cur) {
    s = cur;
    n = s.size();
    memset(f, -1, sizeof(f));
    return dp(0, 0, 1, 1);
}

int good(string cur) {
    int m = cur.size();
    for (int i = 0; i < m - 1; i++) {
        if (cur[i] == cur[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void work() {
    string L, R;
    cin >> L >> R;

    i64 ans = work(R) - work(L) + good(L);
    if (ans >= MOD) {
        ans -= MOD;
    }
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie