/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.10.2024 20:17:07
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

bool workout(int tc) {
    int a, b;
    scanf("%d%d", &a, &b);

    if (a > b) {
        swap(a, b);
    }

    return 2 * a >= b && (a + b) % 3 == 0;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        puts(workout(t) ? "YES" : "NO");
    }
}

// ~ Just Jie