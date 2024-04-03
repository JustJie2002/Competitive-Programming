/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.20.2024 15:41:10
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
    int Q;
    scanf("%d", &Q);

    int a = 0, b = 0;
    for (; Q--; ) {
        int x, y;
        scanf("%d%d", &x, &y);
        a += x;
        b += y;
    }
    
    if (a == b) {
        puts("Draw");
    } else if (a > b) {
        puts("Takahashi");
    } else {
        puts("Aoki");
    }
}

// ~ Just Jie