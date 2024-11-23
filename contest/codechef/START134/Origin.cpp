/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.19.2024 14:14:29
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void work(int tc) {
    i64 x;
    cin >> x;

    i64 ans = (x / 9) * 45;
    x %= 9;
    for (int i = 1; i <= x; i++) {
        ans += i;
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