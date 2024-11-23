/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:19:23
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

const string G = "ABCDEF";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[5];
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    int i = 0;
    while (i < 5 && x < a[i]) {
        i++;
    }
    cout << G[i] << "\n";
}

// ~ JustJie