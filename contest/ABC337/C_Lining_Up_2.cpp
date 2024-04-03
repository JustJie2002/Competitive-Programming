/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.20.2024 15:43:37
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

    vector<int> to(n);
    int x;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == -1) {
            x = i;
        } else {
            t--;
            to[t] = i;
        }
    }

    for (int i = 0; i < n; i++, x = to[x]) {
        printf("%d ", x + 1);
    }
}

// ~ Just Jie