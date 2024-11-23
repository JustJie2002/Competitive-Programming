/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.17.2024 20:44:53
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int x, y, k;
    cin >> x >> y >> k;

    while (x >= y && k > 0) {
        int r = (y - (x % y)) % y;
        if (r > k) {
            x += k;
            k = 0;
        } else {
            x += r;
            k -= r;
            while (x % y == 0) {
                x /= y;
            }
        }
    }
    cout << x << "\n";
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