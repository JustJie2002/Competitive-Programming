/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.10.2024 17:13:35
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

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    i64 ans = 0;
    ans += (2 * n + k - 1) / k;
    ans += (5 * n + k - 1) / k;
    ans += (8 * n + k - 1) / k;
    printf("%lld\n", ans);
}

// ~ Just Jie