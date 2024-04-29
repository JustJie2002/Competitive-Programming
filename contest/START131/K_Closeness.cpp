/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.24.2024 19:18:48
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
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] %= k;
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    n = a.size();

    if (n == 1) {
        puts("0");
    } else {
        int ans = a.back() - a[0];
        for (int i = 1; i < n; i++) {
            ans = min(ans, (a[i - 1] + k) - a[i]);
        }
        printf("%d\n", ans);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie