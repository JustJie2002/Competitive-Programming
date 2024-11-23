/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 12:34:58
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 9, inf = int(1e9) + 5;

int d[N][N];

void work() {
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n - 1; i++) {
        d[s[i] - '1'][s[i + 1] - '1']++;
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    const int cur = s[0] - '1';

    i64 ans = inf;
    do {
        i64 res = 1;
        vector<int> pos(N);
        for (int i = 0; i < N; i++) {
            pos[ord[i]] = i;
        }
        res += pos[cur];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res += 1LL * d[i][j] * (1 + abs(pos[i] - pos[j]));
            }
        }
        ans = min(ans, res);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie