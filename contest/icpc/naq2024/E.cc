/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 14:19:14
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 51;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int f[N] {};
    for (int i = 0; i < 10 * n; i++) {
        for (int j = 0; j < 5; j++) {
            int x;
            cin >> x;
            f[x]++;
        }
    }

    const int m = 2 * n;

    bool exist = false;
    for (int i = 1; i < N; i++) {
        // f[i] > 0.2 * n
        if (f[i] > m) {
            cout << i << " ";
            exist = true;
        }
    }
    if (!exist) {
        cout << -1 << '\n';
    }
}

// ~ JustJie