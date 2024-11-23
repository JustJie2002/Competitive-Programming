/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.02.2024 18:24:06
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

constexpr int N = 9e4 + 1;
int evts[N];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for (; m--; ) {
            int l, r;
            scanf("%d%d", &l, &r);
            r++;
            evts[l]++;
            evts[r]--;
        }
    }

    int ans = 0, res = 0, tot = 0;
    for (int i = 0; i < N; i++) {
        res += evts[i];
        if (res > ans) {
            ans = res;
            tot = 1;
        } else if (res == ans) {
            tot++;
        }
    }

    printf("%d\n", ans);
    printf("%d\n", tot);
}

// ~ Just Jie