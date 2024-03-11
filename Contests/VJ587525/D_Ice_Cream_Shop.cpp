/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.16.2023 02:44:51
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> p(n), x(m);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    
    vector<array<int, 2>> a;
    
    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && x[j] < 100 * i) {
            j++;
        }
        int d = inf;
        if (j < m) {
            d = min(d, abs(100 * i - x[j]));
        }
        if (j > 0) {
            d = min(d, abs(100 * i - x[j - 1]));
        }
        
        a.push_back({100 * i - d, p[i]});
        a.push_back({100 * i + d, -p[i]});
    }
    
    i64 ans = 0, cur = 0;
    sort(a.begin(), a.end());
    for (auto [x, y] : a) {
        cur += y;
        ans = max(ans, cur);
    }
    
    cout << ans << "\n";
}

// ~ Jie ♥ Jenney