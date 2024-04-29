/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.24.2024 20:53:41
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
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        int need = x * v;
        ans += min(need, y);
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie