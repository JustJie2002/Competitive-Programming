/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.18.2024 19:55:33
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    i64 res = 0;
    for (int i = 0; ; i++) {
        res += (1LL << i);
        if (res > x) {
            cout << i + 1 << "\n";
            break;
        }
    }
}

// ~ Just Jie