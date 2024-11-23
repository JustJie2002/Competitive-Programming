/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 17:43:36
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, d, m;
    cin >> s >> d >> m;

    const int S = s.size();
    const int D = d.size();
    const int M = m.size();
    if (D <= 20) {
        int res = 0;
        for (int b = 0; b < D; b++) {
            res += (int(d[b] == '1') << (D - b - 1));
        }
        if (res < min(S, M)) {
            cout << "Infinite money!\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}

// ~ JustJie