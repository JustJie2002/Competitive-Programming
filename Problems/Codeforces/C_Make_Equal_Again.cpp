/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 02:59:46
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

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int l = 0, r = n - 1;
    while (l < n - 1 && a[l] == a[l + 1]) {
        l++;
    }
    while (r > l && a[r] == a[r - 1]) {
        r--;
    }

    dbg(l, r);

    if (l == r) {
        puts("0");
    } else {
        if (a[0] == a[n - 1]) {
            printf("%d\n", r - l - 1);
        } else {
            printf("%d\n", min(
                n - l - 1,
                r
            ));
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie