/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:12:10
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> p(3);
    p[0] = 1;
    for (char c : s) {
        if (c == 'A') {
            swap(p[0], p[1]);
        } else if (c == 'B') {
            swap(p[2], p[1]);
        } else {
            swap(p[0], p[2]);
        }
    }

    cout << int(ranges::find(p, 1) - p.begin()) + 1 << "\n";
}

// ~ JustJie