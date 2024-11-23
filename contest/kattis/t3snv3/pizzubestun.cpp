/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 18:03:56
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> a[i];
    }

    sort(a.begin(), a.end(), greater());

    i64 ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += a[i];
    }

    cout << ans << "\n";
}

// ~ Just Jie