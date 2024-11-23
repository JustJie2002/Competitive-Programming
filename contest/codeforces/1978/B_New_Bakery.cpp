/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.16.2024 17:06:49
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

i64 sum(i64 x) {
    return x * (x + 1) / 2;
}

void work(int tc) {
    int n, a, b;
    cin >> n >> a >> b;

    // a = b - i + 1
    // a + i = b + 1
    // i = (b + 1) - a
    int i = max(0, (b + 1) - a);
    i = min(i, n);

    cout << 1LL * i * (b + 1) - sum(i) + 1LL * (n - i) * a << "\n";
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