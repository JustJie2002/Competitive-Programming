/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.02.2024 09:19:24
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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1) {
            continue;
        }
        int j = i;
        int minv = a[i], maxv = a[i];
        while (minv != i + 1 || maxv != j + 1) {
            j++;
            minv = min(minv, a[j]);
            maxv = max(maxv, a[j]);
        }
        ans += (j - i + 1);
        i = j;
    }

    printf("%d\n", ans);
}

// ~ Just Jie