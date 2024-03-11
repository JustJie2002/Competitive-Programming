/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 11:31:17
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

constexpr int N = 4;

int main() {
    int a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        a += x;
    }
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        b += x;
    }

    if (a < b) {
        puts("Emma");
    } else if (a == b) {
        puts("Tie");
    } else {
        puts("Gunnar");
    }
}

// ~ Just Jie