/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 16:22:34
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, p;
    cin >> n >> p;

    i64 H = n / 2 - p / 2;
    H %= p;
    H = H * 2;
    if (H % p == 0) {
        H = 0;
    }
    cout << H << "\n";
}

// ~ JustJie