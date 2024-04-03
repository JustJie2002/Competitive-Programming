/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.16.2023 02:05:03
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void work() {
    int n, Q;
    cin >> n >> Q;

    int r = 0, w = 0;
    for (; Q--; ) {
        int a, b;
        cin >> a >> b;
        r = max(r, a);
        w = max(w, b);
    }

    if (r + w > n) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << string(r, 'R') + string(n - r, 'W') << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work();
    }
}

// ~ Jie ♥ Jenney