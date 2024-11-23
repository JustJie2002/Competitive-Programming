/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:25:24
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    i64 cur = 1;
    int L = 0;
    while (cur * cur <= n) {
        n -= cur * cur;
        cur += 2;
        L++;
    }
    cout << L << "\n";
}

// ~ JustJie