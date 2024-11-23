/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:10:18
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }

        int p = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int s, t;
            cin >> s >> t;
            ans += s * (t - p);
            p = t;
        }
        cout << ans << " miles" << "\n";
    }
}

// ~ JustJie