/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.06.2024 21:30:27
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int A = 26;

void work(int tc) {
    string s;
    cin >> s;
    int n = s.size();

    int cnt[A] {};
    for (auto c : s) {
        cnt[c - 'a']++;
    }

    int ans = n;
    for (int a = 0; a < A; a++) {
        ans = min(ans, n - cnt[a]);
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