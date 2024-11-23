/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 13:39:38
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int inf = int(1e9) + 5;

void work() {
    int s, p;
    cin >> s >> p;
    p = 100 - p;

    double dec = 1. * p / 100;

    // n * s * (p / 100) ^ n

    double cur = 0;
    double ans = 0;
    do {
        cur += s;
        if (cur - ans <= 1e-6) {
            break;
        }
        ans = cur;
        cur *= dec;
    } while (true);
    cout << fixed << setprecision(7) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie