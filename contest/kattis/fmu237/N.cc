/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 12:22:49
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

void work() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    map<array<int, 3>, i64> f;
    const auto dfs = [&](auto&& self, int i, int one, int two, int size) -> i64 {
        if (size >= 2 && f.contains({i, one + two, size})) {
            return f[{i, one + two, size}];
        }
        if (i == n) {
            return int(size >= 3);
        }

        i64 ans = self(self, i + 1, one, two, size);
        if (one == -1) {
            ans += self(self, i + 1, s[i], two, size + 1);
        } else if (two == -1) {
            ans += self(self, i + 1, one, s[i], size + 1);
        } else if (one + two > s[i]) {
            ans += self(self, i + 1, one, two, size + 1);
        }
        return f[{i, one + two, size}] = ans;
    };
    cout << dfs(dfs, 0, -1, -1, 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie