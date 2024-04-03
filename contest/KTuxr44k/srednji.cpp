/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.21.2023 15:45:16
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

using i64 = long long;

int main() {
    int n, med;
    scanf("%d%d", &n, &med);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int pivot = int(find(a.begin(), a.end(), med) - a.begin());

    array<map<int, int>, 2> cnt;
    for (int i = 0; i < 2; i++) {
        cnt[i].clear();
    }
    int p = 0;
    i64 ans = 0;
    for (int i = pivot; i < n; i++) {
        if (a[i] < med) {
            p++;
        } else if (a[i] > med) {
            p--;
        }
        cnt[(i - pivot) & 1][p]++;
    }

    p = 0;
    for (int i = pivot; i >= 0; i--) {
        if (a[i] < med) {
            p++;
        } else if (a[i] > med) {
            p--;
        }
        ans += cnt[(pivot - i) & 1][-p];
    }

    printf("%lld\n", ans);
}