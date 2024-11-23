/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.22.2024 01:52:07
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    string s;
    cin >> s;
    
    int n = s.size();
    i64 p;
    cin >> p;
    p--;

    int g = 0;
    while (n - g <= p) {
        p -= (n - g);
        g++;
    }

    string ans;
    for (auto c : s) {
        while (g > 0 && !ans.empty() && c < ans.back()) {
            ans.pop_back();
            g--;
        }
        ans += c;
    }

    cout << ans[p];
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