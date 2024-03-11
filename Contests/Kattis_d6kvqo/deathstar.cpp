/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 10:09:57
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
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            int msk;
            scanf("%d", &msk);
            res |= msk;
        }
        printf("%d%c", res, " \n"[i == n - 1]);
    }
}

// ~ Just Jie