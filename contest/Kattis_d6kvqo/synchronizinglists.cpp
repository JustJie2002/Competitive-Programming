/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 09:59:37
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
using Info = pair<int, int>;

#define f   first
#define s   second

void work(int n) {
    vector<Info> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].f);
        a[i].s = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[a[i].s] = b[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    printf("\n");
}

int main() {
    int n;
    while (~scanf("%d", &n), n != 0) {
        work(n);
    }
}

// ~ Just Jie