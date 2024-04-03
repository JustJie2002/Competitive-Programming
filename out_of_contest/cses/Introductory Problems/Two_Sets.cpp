/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.10.2024 18:56:45
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

    if (n % 4 == 0) {
        puts("YES");
        printf("%d\n", n / 2);
        for (int i = 1; i <= n / 4; i++) {
            printf("%d %d%c", i, n - i + 1, " \n"[i == n / 4]);
        }
        printf("%d\n", n / 2);
        for (int i = n / 4 + 1; i <= n / 2; i++) {
            printf("%d %d%c", i, n - i + 1, " \n"[i == n / 2]);
        }
    } else if ((n + 1) % 4 == 0) {
        puts("YES");
        printf("%d\n", n / 2 + 1);
        for (int i = 1; i <= (n + 1) / 4; i++) {
            printf("%d %d%c", i, n - i, " \n"[i == (n + 1) / 4]);
        }
        printf("%d\n", n / 2);
        for (int i = (n + 1) / 4 + 1; i <= n / 2; i++) {
            printf("%d %d ", i, n - i);
        }
        printf("%d\n", n);
    } else {
        puts("NO");
    }
}

// ~ Just Jie