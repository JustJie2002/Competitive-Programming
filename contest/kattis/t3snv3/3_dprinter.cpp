/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 18:10:30
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = inf;
    int res = 1;
    int days = 0;
    do {
        ans = min(ans, days + (n + res - 1) / res);
        res *= 2;
        days++;
    } while (res <= n);
    cout << ans << "\n";
}

// ~ Just Jie