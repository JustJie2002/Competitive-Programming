/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.03.2024 10:36:52
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    array<int, 7> cnt {};
    for (auto c : s) {
        cnt[c - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans += max(0, m - cnt[i]);
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

// ~ Just Jie