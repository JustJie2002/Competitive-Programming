/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.20.2024 12:31:55
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

constexpr int inf = int(1e9) + 5;

void work() {
    int n, w;
    cin >> n >> w;

    vector<string> s(n);
    vector<int> siz(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        siz[i] = s[i].size();
    }
    const auto check = [&](int m) {
        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = i; j < n && j < i + m; j++) {
                mx = max(mx, siz[j]);
                if (dp[i] + mx + int(j != n - 1) <= w) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + mx + int(j != n - 1));
                }
            }
        }
        return dp[n] <= w;
    };

    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    const auto construct = [&](int row) {
        vector<int> dp(n + 1, inf);
        vector<int> col(n + 1);
        vector<int> from(n + 1);
        vector<int> length(n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = i; j < n && j < i + row; j++) {
                mx = max(mx, siz[j]);
                if (dp[i] + mx + int(j != n - 1) <= w) {
                    if (dp[i] + mx + int(j != n - 1) < dp[j + 1]) {
                        dp[j + 1] = dp[i] + mx + int(j != n - 1);
                        col[j + 1] = col[i] + 1;
                        from[j + 1] = i + 1;
                        length[j + 1] = mx;
                    }
                }
            }
        }
        cout << row << " " << col[n] << "\n";
        vector<array<int, 2>> seg;
        vector<int> lengths;
        int back = n;
        while (back != 0) {
            int to = from[back];
            seg.push_back({to - 1, back - 1});
            lengths.push_back(length[back]);
            back = to - 1;
        }
        reverse(lengths.begin(), lengths.end());
        reverse(seg.begin(), seg.end());
        for (int x : lengths) {
            cout << x << " ";
        }
        cout << "\n";
        vector<vector<string>> col_string(col[n]);
        int cur = 0;
        for (const auto& [i, j] : seg) {
            for (int k = i; k <= j; k++) {
                col_string[cur].push_back(s[k]);
            }
            cur++;
        }
        
        for (int r = 0; r < row; r++) {
            string cur;
            for (int c = 0; c < col[n]; c++) {
                if (col_string[c].size() <= r) {
                    cur += string(lengths[c], ' ');
                } else {
                    cur += col_string[c][r];
                    cur += string(lengths[c] - col_string[c][r].size(), ' ');
                }
                if (c < col[n] - 1) {
                    cur += " ";
                } else {
                    cur += "\n";
                }
            }
            cout << cur;
        }
    };

    construct(hi);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie