/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.18.2024 22:04:18
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int a, b, c;
    cin >> a >> b >> c;

    // (B | C_i) - (A & C_i)

    const auto has = [&](int mask, int nth) {
        return mask >> nth & 1;
    };

    int ans = 1;
    for (int i = c - 1; i >= 0; i--) {
        if (has(a, i) != has(b, i)) {
            ans *= 2;
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