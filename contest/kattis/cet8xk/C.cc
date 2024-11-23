/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 16:18:25
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int t = 0;
    if (n & 1) {
        t = 1;
        n -= 3;
    }

    cout << t + (n / 2) << "\n";
    for (int i = 0; i < n / 2; i++) {
        cout << 2 << " ";
    }
    if (t) {
        cout << 3 << " ";
    }
}

// ~ JustJie