/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 14:17:31
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work() {
    int n, w;
    cin >> n >> w;
    w *= 60;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int streak = 0;
        int cur = w;
        for (int j = i; j < n; j++) {
            if (cur >= 2 * a[j]) {
                cur -= 2 * a[j];
                streak++;
            } else {
                streak = 0;
            }
            ans = max(ans, streak);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie