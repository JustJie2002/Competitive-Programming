/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.06.2024 10:42:21
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

string to_binary(int x) {
    string s;
    while (x) {
        s += char('0' + (x & 1));
        x >>= 1;
    }
    if (s.empty()) {
        return "0";
    }
    return s;
}

void work(int tc) {
    int x, y;
    cin >> x >> y;

    // cout << to_binary(x) << "\n";
    // cout << to_binary(y) << "\n";

    int ans = 1;
    for (int i = 0; i < 30; i++) {
        if (((x >> i) & 1) == ((y >> i) & 1)) {
            ans += (1 << i);
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