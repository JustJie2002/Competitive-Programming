/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 19:54:54
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int ans = 1;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            ans *= 2;
        }
    }
    cout << ans << "\n";
}

// ~ Just Jie