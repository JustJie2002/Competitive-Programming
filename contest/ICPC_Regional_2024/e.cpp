/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.30.2023 01:41:29
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

using i64 = long long;
using Info = pair<i64, i64>;

constexpr int MAXN = 5;
Info a[MAXN];

#define f   first
#define s   second

int main() {
    for (int i = 0; i < MAXN; i++) {
        scanf("%lld%lld", &a[i].f, &a[i].s);
    }

    i64 e, k;
    scanf("%lld%lld", &e, &k);

    i64 ans = 0;
    for (int i = 0; i < MAXN; i++) {
        i64 res = a[i].f * a[i].s * e;
        ans += res;
    }

    printf("%lld\n", ans / (k * MAXN));
}

// ~ Jie ♥ Jenney