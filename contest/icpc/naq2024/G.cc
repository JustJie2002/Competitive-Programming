/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 14:36:03
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, vector<int>> f;
    int mx = 0; 
    for (int i = 0; i < n; i++) {
        int g, x;
        cin >> g >> x;
        mx = max(mx, x);

        f[g].push_back(x);
    }

    // vector<array<int, 2>> grps;
    double ans = 0;
    for (auto& [k, v] : f) {
        sort(v.begin(), v.end());
        deque<int> dq(v.begin(), v.end());
        while (dq.size() > 1) {
            ans += log(1. * dq.back() / dq.front());
            dq.pop_back();
            dq.pop_front();
        }
    }

    cout << fixed << setprecision(7);
    cout << ans << "\n";
}

// ~ JustJie