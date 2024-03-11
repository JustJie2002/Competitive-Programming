/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.05.2024 10:25:47
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

void workout(int tc) {
    int n, c;
    scanf("%d%d", &n, &c);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    i64 ans = 1LL * (c + 1) * (c + 2) / 2;

    array<int, 2> par {};
    for (int x : a) {
        ans -= x / 2 + 1;
        ans -= max(0, c - x + 1);
        ans += ++par[x & 1];
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie