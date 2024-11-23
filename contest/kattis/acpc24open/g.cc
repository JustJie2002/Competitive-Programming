/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 13:57:52
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int inf = int(1e9) + 5;

void work() {
    int n, s, m;
    cin >> n >> s >> m;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    auto good = [&](int t) {
        int streak = 0;
        int y = 0;
        for (int x : d) {
            if (t <= x) {
                streak++;
                if (streak == s) {
                    streak = 0;
                    y++;
                }
            } else {
                streak = 0;
            }
        }
        return y >= m;
    };

    int lo = 0, hi = inf;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (good(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie