/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.17.2024 20:30:35
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int x, y;
    cin >> x >> y;

    const auto has_bit = [&](int mask, int nth) {
        return mask & (1 << nth);
    };

    int ans = 1;
    for (int b = 0; ; b++) {
        if (has_bit(x, b) == has_bit(y, b)) {
            ans += (1 << b);
        } else {
            break;
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

// ~ Just Jie