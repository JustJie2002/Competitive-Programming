/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:34:38
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n;
    cin >> n;

    int t = 0;
    int cnt = 0;
    int res = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (t == x) {
            cnt++;
        } else if (x > t) {
            cnt = 1;
            t = x;
            cur = i + 1;
        }
        res += x;
    }

    if (cnt > 1) {
        cout << "no winner\n";
    } else if (2 * t > res) {
        cout << "majority winner " << cur << "\n";
    } else {
        cout << "minority winner " << cur << "\n";
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