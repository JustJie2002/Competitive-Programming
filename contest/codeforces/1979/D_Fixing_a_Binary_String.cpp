/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.06.2024 11:13:37
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Info = pair<char, int>;

void work(int tc) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> good;
    bool first = true;
    char p = s[n - 1];
    int cnt = 0;
    Info want = pair(p, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == p) {
            cnt++;
        } else {
            if (first) {
                want.second = (k - cnt) % k;
                first = false;
            } else if (cnt != k) {
                break;
            }
            p = s[i];
            cnt = 1;
        }
        if (cnt == k) {
            good.push_back(i);
        } else if (cnt > k) {
            break;
        }
    }
    if (first) {
        if (cnt > k) {
            cout << "-1\n";
            return;
        }
        want.second = (k - cnt) % k;
    }

    vector<Info> pre(n);
    vector<bool> good_pref(n);
    pre[0] = pair(s[0], 1);
    if (k == 1) {
        good_pref[0] = true;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            pre[i] = pair(s[i], 1);
        } else {
            pre[i] = pre[i - 1];
            pre[i].second++;
        }
        if (pre[i].second == k) {
            if (i + 1 == k) {
                good_pref[i] = true;
            } else {
                good_pref[i] = good_pref[i - k];
            }
        }
    }

    auto work = [&](int i) -> bool {
        if (want.second > 0) {
            if (i < want.second) {
                return false;
            }
            if (pre[i - 1] != want) {
                return false;
            }
        } else if (i && s[i - 1] == s[n - 1]) {
            return false;
        }
        i -= want.second;
        if (i == 0) {
            return true;
        }
        return good_pref[i - 1];
    };

    if (!good.empty() && good.back() == 0) {
        cout << n << "\n";
        return;
    }

    for (int i : good) {
        if (work(i)) {
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
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