/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 11:05:53
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
    int n, m;
    scanf("%d%d", &n, &m);

    // ax + by = n
    // x + y = m
    // abs(x - y) <= 0

    if (m % n == 0) {
        for (int i = 0; i < n; i++) {
            printf("%s\n", string(m / n, '*').c_str());
        }
    } else {
        for (int p = 2; p <= m; p++) {
            for (int i = 1; i <= n; i++) {
                int cur = i * p;
                int res = m - i * p;
                if (res <= 0) break;
                if ((p - 1) * (n - i) == res) {
                    for (int _ = 0; _ < i; _++) {
                        printf("%s\n", string(p, '*').c_str());
                    }
                    for (int _ = 0; _ < n - i; _++) {
                        printf("%s\n", string(p - 1, '*').c_str());
                    }
                    return 0;
                }
            }
        }
    }
}

// ~ Just Jie