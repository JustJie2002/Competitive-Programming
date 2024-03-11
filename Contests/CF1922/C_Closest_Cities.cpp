/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.18.2024 13:24:40
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

    vector<int> pre(n), suf(n);
    for (int i = 0; i < n - 1; i++) {
        pre[i + 1] = pre[i];
        if (i == 0 || (a[i] - a[i - 1] > a[i + 1] - a[i])) {
            pre[i + 1]++;
        } else {
            pre[i + 1] += (a[i + 1] - a[i]);
        }
    }
    for (int i = n - 1; i; i--) {
        suf[i - 1] = suf[i];
        if (i == n - 1 || (a[i + 1] - a[i] > a[i] - a[i - 1])) {
            suf[i - 1]++;
        } else {
            suf[i - 1] += (a[i] - a[i - 1]);
        }
    }

    int Q;
    scanf("%d", &Q);
    for (; Q--; ) {
        int p, q;
        scanf("%d%d", &p, &q);
        p--, q--;
        if (p < q) {
            printf("%d\n", pre[q] - pre[p]);
        } else {
            printf("%d\n", suf[q] - suf[p]);
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