/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.28.2024 20:18:17
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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    auto work = [&]() {
        vector<int> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] | a[i];
        }
        int x = a[0];
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            x &= a[i];
            res = max(res, abs(x - suf[i + 1]));
        }
        return res;
    };  

    int ans = work();
    reverse(a.begin(), a.end());
    ans = max(ans, work());
    printf("%d\n", ans);
}

// ~ Just Jie