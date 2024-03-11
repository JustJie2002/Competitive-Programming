/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 18:37:32
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
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    int Q;
    scanf("%d", &Q);

    for (; Q--; ) {
        int l, u;
        scanf("%d%d", &l, &u);

        auto gau = [&](int x) -> i64 {
            return 1LL * x * (x + 1) / 2;
        };

        auto get = [&](int r) -> i64 {
            i64 sec = pre[r] - pre[l - 1];
            return 1LL * sec * u - gau(sec - 1);
        };

        int lo = l, hi = n, mid, ans = l;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (get(mid) >= get(mid + 1)) {
                ans = mid;
                hi = mid;
            } else {
                ans = mid + 1;
                lo = mid + 1;
            }
        }

        printf("%d ", ans);
    }
    puts("");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie