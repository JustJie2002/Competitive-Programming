/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 02:20:36
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
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        int sum = 0;
        int cnt = 0;
        while (j < n) {
            sum += a[j];
            cnt++;
            if (a[j] * cnt - sum < 20) {
                j++;
            } else {
                break;
            }
        }
        i = j;
        ans++;
    }
    cout << ans << "\n";
}

// ~ JustJie