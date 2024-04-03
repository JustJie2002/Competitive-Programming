/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.12.2023 10:55:08
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void work() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            map<char, int> freq;
            freq[s[i][j]]++;
            freq[s[n - j - 1][i]]++;
            freq[s[n - i - 1][n - j - 1]]++;
            freq[s[j][n - i - 1]]++;
            while (freq.size() != 1) {
                auto [cur, f] = *freq.begin();
                freq.erase(freq.begin());
                ans += f * (freq.begin()->first - cur);
                freq.begin()->second += f;
            }
        }
    }

    cout << ans << "\n";
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