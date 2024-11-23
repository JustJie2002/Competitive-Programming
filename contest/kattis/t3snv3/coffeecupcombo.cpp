/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 17:55:34
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    int res = 0;
    for (auto c : s) {
        if (c == '1') {
            ans++;
            res = 2;
        } else if (res) {
            ans++;
            res--;
        }
    }

    cout << ans << "\n";
}

// ~ Just Jie