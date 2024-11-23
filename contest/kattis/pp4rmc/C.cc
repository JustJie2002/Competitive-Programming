/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:32:14
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[5] {};
    int res = 0;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            a[i] += x;
        }
        if (a[i] > res) {
            res = a[i];
            ans = i;
        }
    }

    cout << ans + 1 << " " << res << "\n";
}

// ~ JustJie