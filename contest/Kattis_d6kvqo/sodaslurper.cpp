/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 10:05:11
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
    int e, f, c;
    scanf("%d%d%d", &e, &f, &c);
    e += f;

    int ans = 0;
    while (e >= c) {
        int can_drink = e / c;
        ans += can_drink;
        e %= c;
        e += can_drink;
    }

    printf("%d\n", ans);
}

// ~ Just Jie