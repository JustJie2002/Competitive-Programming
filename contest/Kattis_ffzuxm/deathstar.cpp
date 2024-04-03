/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 16:38:32
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

    vector mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int val = 0;
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            val |= x;
        }
        printf("%d%c", val, " \n"[i == n - 1]);
    }
}

// ~ Just Jie