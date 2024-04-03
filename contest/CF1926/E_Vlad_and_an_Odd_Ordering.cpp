/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.20.2024 01:27:13
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

void workout(int tc) {
    int n, k;
    scanf("%d%d", &n, &k);

    int p = 1;
    while (true) {
        int t = (n + 1) / 2;
        if (k <= t) {
            printf("%d\n", (2 * k - 1) * p);
            return;
        }
        k -= t;
        n /= 2;
        p *= 2;
    }

    assert(NULL);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie