/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 16:17:11
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 3;

int frac[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    cin >> L;
    for (int i = 0; i < N; i++) {
        cin >> frac[i][0] >> frac[i][1];
    }

    for (int i = 0; i <= L; i++) {
        int res = 0;
        for (int j = 0; j < 3; j++) {
            int quo = frac[j][0] / frac[j][1];
            int rem = frac[j][0] % frac[j][1];
            if (quo == 1 && rem != 0) {
                res++;
            }
            frac[j][0] = rem * 3;
        }
        if (res > 1) {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1 << "\n";
}

// ~ JustJie