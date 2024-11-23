/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 01:43:30
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int ALL = (1 << 10) - 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    cin >> N;

    int mask = 0;
    for (i64 x = N; x; x /= 10) {
        int d = x % 10;
        mask |= (1 << d);
    }

    mask ^= ALL;

    string s = to_string(N);

    if (mask == 0) {
        cout << "Impossible\n";
    } else {
        int mi = 10;
        int ma = -1;
        int f = s[0] - '0';
        int ff = -1;
        int ss = -1;
        int mi2 = 10;
        for (int i = 0; i < 10; i++) {
            if (mask & (1 << i)) {
                if (mi != 10) {
                    mi2 = min(mi2, i);
                }
                mi = min(mi, i);
                ma = max(ma, i);
                if (i < f) {
                    ff = i;
                } else if (ss == -1) {
                    ss = i;
                }
            }
        }

        vector<i64> ans;
        string ans1, ans3 = "0";
        if (ff != -1) {
            ans1 = string(1, ff + '0');
        } else {
            ans1 = "0";
        }
        while (ans1.size() != s.size()) {
            ans1 += char(ma + '0');
        }
        while (ans3.size() != s.size()) {
            ans3 += char(ma + '0');
        }

        ans.push_back(stoll(ans1));
        ans.push_back(stoll(ans3));
        string ans2, ans4;
        if (ss != -1) {
            ans2 = string(1, ss + '0');
        } else {
            ans2 = "0";
        }
        if (mi == 0) {
            if (mi2 != 10) {
                ans4 = string(1, mi2 + '0');
            }
        }
        while (ans2.size() != s.size()) {
            ans2 += char(mi + '0');
        }
        while (ans4.size() < s.size() + 1) {
            ans4 += char(mi + '0');
        }
        ans.push_back(stoll(ans2));
        ans.push_back(stoll(ans4));

        vector<i64> res {ans[0]};
        i64 piv = ans[0];
        for (i64 x : ans) {
            if (abs(x - N) < abs(piv - N)) {
                res.clear();
                res.push_back(x);
            } else if (abs(x - N) == abs(piv - N)) {
                res.push_back(x);
            }
        }

        set<i64> uni(res.begin(), res.end());
        for (i64 x : uni) {
            cout << x << " ";
        }
    }
}

// ~ Just Jie