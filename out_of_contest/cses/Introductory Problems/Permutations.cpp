/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.10.2024 18:47:45
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

    if (n == 1) {
        puts("1");
    } else if (n <= 3) {
        puts("NO SOLUTION");
    } else {
        for (int i = 2; i <= n; i += 2) {
            printf("%d ", i);
        }
        for (int i = 1; i <= n; i += 2) {
            printf("%d ", i);
        }
        puts("");
    }
}

// ~ Just Jie