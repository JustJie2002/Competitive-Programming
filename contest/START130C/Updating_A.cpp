/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.17.2024 11:11:49
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

void work(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pre[i + 1] = pre[i] + a[i];
    }

    if (n == 1) {
        printf("%d\n", a[0]);
        return;
    }

    // do reverse kadane
    int s = 0;
    i64 res = 0;
    i64 ans = abs(pre[n]);
    for (int e = 0; e < n; e++) {
        res -= a[e];
        if (res < -a[e]) {
            s = e;
            res = -a[e];
        }
        if (e - s > 0) {
            ans = max(ans, res + pre[s] + (pre[n] - pre[e + 1]));
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie