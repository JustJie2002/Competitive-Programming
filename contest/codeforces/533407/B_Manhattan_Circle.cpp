/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.17.2024 20:26:21
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

void work(int tc) {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    Info top {-1, -1};
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#' && top[0] == -1) {
                top = {i, j};
            }
        }
    }

    Info bot = top;
    while (bot[0] < n && s[bot[0]][bot[1]] == '#') {
        bot[0]++;
    }
    bot[0]--;

    Info mid {
        (bot[0] + top[0]) / 2 + 1,
        bot[1] + 1
    };
    cout << mid[0] << " " << mid[1] << "\n";
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