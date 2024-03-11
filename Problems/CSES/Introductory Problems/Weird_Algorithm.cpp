/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.10.2024 18:40:15
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
    i64 n;
    scanf("%lld", &n);

    while (n != 1) {
        printf("%lld ", n);
        if (n & 1) {
            n = 3LL * n + 1;
        } else {
            n >>= 1;
        }
    }

    puts("1");
}

// ~ Just Jie