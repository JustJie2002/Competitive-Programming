/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 11.17.2024 16:00:15
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

/*

3 4 5
9, 16, 25

0, 9, 25

26 - 9 = 17
*/


void work(int tc) {
    int n;
    cin >> n;

    if (n & 1) {
        if (n <= 25) {
            cout << "-1\n";
        } else {
            vector<int> a(n);
            a[0] = a[9] = a[25] = 1;
            a[22] = a[26] = 2;
            for (int i = 1; i <= 8; i++) {
                a[i] = 2 + (i + 1) / 2;
            }
            // 1 2 3 4 5 6
            for (int i = 10; i < 22; i++) {
                a[i] = 7 + (i - 10) / 2;
            }
            // 7 8 9 10 11 12
            a[23] = a[24] = 13;
            for (int i = 27; i < n; i++) {
                a[i] = 14 + (i - 27) / 2;
            }
            for (int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == n - 1];
            }
        }
    } else {
        for (int i = 0; i < n / 2; i++) {
            cout << (i + 1) << " " << (i + 1) << " \n"[i == n / 2 - 1];
        }
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