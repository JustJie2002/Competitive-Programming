/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 12:14:43
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int res = m;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int b = 0; b < m; b++) {
                if (int(s[i][b] == 'F') == (mask >> b & 1)) {
                    cur++;
                }
            }
            res = min(res, cur);
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie