/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 11.17.2024 15:46:27
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n;
    cin >> n;

    map<int, int> f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }

    int ans = n;
    for (auto& [k, v] : f) {
        ans = min(ans, n - v);
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