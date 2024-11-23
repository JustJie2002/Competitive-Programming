/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.15.2024 03:36:06
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n, m, Q;
    cin >> n >> m >> Q;

    set<int> s;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (; Q--; ) {
        int q;
        cin >> q;

        auto it = s.lower_bound(q);
        int ans = n;
        if (it == s.end()) {
            ans = n - *prev(it);
        } else if (it == s.begin()) {
            ans = *it - 1;
        } else {
            int dis = *it - *prev(it);
            ans = dis / 2;
        }
        cout << ans << "\n";
    }
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