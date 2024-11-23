/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 13:34:15
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work() {
    int n;
    cin >> n;

    int cur = 0;
    while (n--) {
        int op, x;
        cin >> op >> x;
        if (op == 0) {
            cur += x;
        } else if (op == 1) {
            cur -= x;
        }
        cur = max(cur, 0);
    }
    cout << cur << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Ji6