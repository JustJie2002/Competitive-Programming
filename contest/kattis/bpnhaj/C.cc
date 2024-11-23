/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:08:02
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int inf = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    unordered_map<char, int> f;
    for (char c : s) {
        f[c]++;
    }

    int ans = 0;
    int res = 0;
    if (f.size() == 3) {
        res = inf;
    }
    for (const auto& [k, v] : f) {
        ans += v * v;
        res = min(res, v);
    }
    ans += res * 7;
    cout << ans << "\n";
}

// ~ JustJie