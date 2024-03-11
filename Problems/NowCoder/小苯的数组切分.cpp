/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.03.2024 19:43:46
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

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    i64 ans = a.back();
    a.pop_back();
    n--;

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] ^ a[i];
    }
    i64 suf = 0;
    i64 res = 0;
    for (int i = n - 1; i > 0; i--) {
        suf |= a[i];
        res = max(res, pre[i] + suf);
    }
    ans += res;

    printf("%lld\n", ans);
}

// ~ Just Jie