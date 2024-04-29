/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.17.2024 11:24:01
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

void work(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (a[0] != a[n - 1]) {
        puts("NO");
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[0]) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie