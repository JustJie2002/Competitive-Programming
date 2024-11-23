/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 17:58:28
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    int ans = 0;
    for (i64 x = 1; n >= x * x; x += 2) {
        ans++;
        n -= x * x;
    }
    cout << ans << "\n";
}

// ~ Just Jie