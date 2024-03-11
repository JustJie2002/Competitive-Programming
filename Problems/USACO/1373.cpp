/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.22.2024 01:25:17
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

    i64 ans = 0, acc = 0;
    for (int i = 0; i < n; i++) {
        i64 x;
        scanf("%lld", &x);
        sum += x;
    }

    dbg(sum);
}

// ~ Just Jie