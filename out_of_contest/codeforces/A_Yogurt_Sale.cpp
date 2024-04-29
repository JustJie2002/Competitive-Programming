/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.19.2024 00:48:30
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

void work(int tc) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    b = min(b, 2 * a);
    int res = (n / 2) * b;
    res += (n & 1) * a;
    printf("%d\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie