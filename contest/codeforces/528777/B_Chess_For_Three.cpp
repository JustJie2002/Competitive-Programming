/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 12:55:29
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b + c) & 1) {
        cout << -1 << "\n";
        return;
    }

    if (c >= a + b) {
        cout << a + b << "\n";
    } else {
        cout << (a + b + c) / 2 << "\n";
    }
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