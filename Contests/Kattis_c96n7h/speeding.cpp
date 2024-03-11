/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.30.2024 02:33:03
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;
using Info = pair<int, int>;

int main() {
    int n;
    scanf("%d", &n);

    vector<Info> info(n);
    for (auto& [t, d] : info) {
        scanf("%d%d", &t, &d);
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int d = info[i].second - info[i - 1].second;
        int t = info[i].first - info[i - 1].first;
        ans = max(ans, d / t);
    }

    printf("%d\n", ans);
}

// ~ Just Jie