/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.25.2023 18:08:41
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

using i64 = long long;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
    }

    vector<i64> pre(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    int L, R;
    scanf("%d%d", &L, &R);
    L--, R--;

    int m = R - L;
    int res = n;
    i64 ans = 0;
    for (int i = m; i <= 2 * n; i++) {
        i64 cur_sum = pre[i] - pre[i - m];
        if (cur_sum >= ans) {
            ans = cur_sum;
            res = min<int>(res, ((L - (i - m) + n) % n) + 1);
        }
    }

    L -= res;
    if (L < 0) L += n;

    printf("%d\n", L + 1);
}

// ~ Jie ♥ Jenney