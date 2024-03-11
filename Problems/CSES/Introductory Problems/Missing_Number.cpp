/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.10.2024 18:41:49
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

    i64 sum = 1LL * n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        int x;
        scanf("%d", &x);
        sum -= x;
    }

    printf("%lld\n", sum);
}

// ~ Just Jie