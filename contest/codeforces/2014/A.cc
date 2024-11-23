/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.22.2024 17:22:31
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= k) {
            cur += x;
        } else if (x == 0 && cur) {
            cur--;
            ans++;
        }
    }
    cout << ans << "\n";
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

// ~ JustJie