/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.22.2024 17:40:11
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr i64 inf64 = i64(1e15) + 5;

void work(int tc) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << -1 << '\n';
        return;
    }

    ranges::sort(a);
    int mid = n / 2;
    i64 piv = 2LL * n * a[mid];

    i64 sum = accumulate(a.begin(), a.end(), 0LL);
    i64 lo = 0, hi = inf64;
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if ((sum + mid) > piv) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << hi << "\n";
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