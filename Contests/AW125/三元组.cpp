/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2023 20:17:58
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

using i128 = __int128;

using i64 = long long;
using Pair = pair<int, int>;

int main() {    
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<Pair> L(n), R(n);
    Pair mi(a[0], 1);
    for (int i = 1; i < n; i++) {
        L[i] = mi;
        if (a[i] < mi.first) {
            mi = make_pair(a[i], 1);
        } else if (a[i] == mi.first) {
            mi.second++;
        }
    }
    mi = make_pair(a[n - 1], 1);
    for (int i = n - 2; i >= 0; i--) {
        R[i] = mi;
        if (a[i] < mi.first) {
            mi = make_pair(a[i], 1);
        } else if (a[i] == mi.first) {
            mi.second++;
        }
    }

    i128 res = (i128) a[0] * a[1] * a[2];
    for (int i = 1; i < n - 1; i++) {
        res = min(res, (i128) L[i].first * a[i] * R[i].first);
    }

    i64 ans = 0;
    for (int i = 1; i < n - 1; i++) {
        i128 cur = (i128) L[i].first * a[i] * R[i].first;
        if (res == cur) {
            ans += 1LL * L[i].second * R[i].second;
        }
    }

    printf("%lld\n", ans);
}

// ~ Jie ♥ Jenney