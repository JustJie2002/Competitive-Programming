/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.31.2024 23:18:51
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

array<i64, 2> divmod(i64 v, i64 mod) {
    assert(mod != 0);
    return {
        v / mod,
        v % mod
    };
}

void workout(int tc) {
    int n, m;
    i64 v;
    scanf("%d%d%lld", &n, &m, &v);
    v--;

    auto [r, c] = divmod(v, n);
    printf("%lld\n", c * m + r + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie