/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.16.2023 01:59:52
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void work() {
    int n;
    cin >> n;

    map<int, int> dict;
    for (int i = 0; i < n; i++) {
        int b, x;
        cin >> b >> x;
        dict[x] = max(dict[x], b);
    }

    if (dict.size() != 10) {
        cout << "MOREPROBLEMS\n";
    } else {
        int res = 0;
        for (auto &[_, x] : dict) {
            res += x;
        }
        cout << res << "\n";
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