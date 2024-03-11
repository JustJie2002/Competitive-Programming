/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.22.2024 10:21:10
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

int main() {
    int n;
    scanf("%d", &n);

    double res = 0.;
    for (int i = 0; i < n; i++) {
        int m, s;
        scanf("%d%d", &m, &s);
        res += 1. * m / s;
    }

    printf("%.7lf\n", (res * 100) / n);
}

// ~ Just Jie