/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.10.2024 18:50:46
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
    int r, c;
    scanf("%d%d", &r, &c);

    int mx = max(r, c);
    i64 sq1 = 1LL * mx * mx;
    i64 sq2 = 1LL * (mx - 1) * (mx - 1);
    i64 res;

    if (r > c) {
        if (r & 1) {
            res = sq2 + c;
        } else {
            res = sq1 - (c - 1);
        }
    } else if (r < c) {
        if (c & 1) {
            res = sq1 - (r - 1);
        } else {
            res = sq2 + r;
        }
    } else {
        res = sq1 - (r - 1);
    }

    printf("%lld\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie