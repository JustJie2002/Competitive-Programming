/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 09:37:41
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
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if ((a < b && c < b) || (a > b && c > b)) {
        puts("turned");
        return 0;
    }

    int s = b - a;
    int e = c - b;
    if (s == e) {
        puts("cruised");
    } else if (abs(s) < abs(e)) {
        puts("accelerated");
    } else {
        puts("braked");
    }
}

// ~ Just Jie