/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 03:03:42
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
using Pair = pair<int, int>;

void workout(int tc) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    map<Pair, int> occ;
    i64 ans = 0;
    for (int e : a) {
        int wsub = (e % y);
        int wadd = x - (e % x);
        if (wadd == x) wadd = 0;
        ans += occ[make_pair(wadd, wsub)];
        int xrem = e % x;
        int yrem = e % y;
        occ[make_pair(xrem, yrem)]++;
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie