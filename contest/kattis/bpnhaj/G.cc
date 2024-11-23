/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:15:42
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    cout << int(a[3] <= a[1] - 2 && a[2] <= a[0] - 2) << "\n";
}

// ~ JustJie