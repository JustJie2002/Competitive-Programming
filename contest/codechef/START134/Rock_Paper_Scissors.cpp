/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.19.2024 14:07:19
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> groupby(int n, string& s) {
    s += '$';

    auto p = s[0];
    auto cnt = 0;
    vector<int> res;
    for (auto c : s) {
        if (c == p) {
            cnt++;
        } else {
            res.push_back(cnt);
            cnt = 1;
        }
        p = c;
    }

    return res;
}

void work(int tc) {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (auto x : groupby(n, s)) {
        ans += (x + 1) / 2;
    }
    cout << ans << "\n";
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