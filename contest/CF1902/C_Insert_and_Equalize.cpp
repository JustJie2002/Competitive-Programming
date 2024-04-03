/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.04.2023 23:54:02
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

using i64 = long long;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<i64> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    sort(a.begin(), a.end());

    i64 g = 0;
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
    }

    if (g == 0) {
        puts("1");
    } else {
        i64 res = a.back() + g;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] - g != a[i - 1]) {
                res = a[i] - g;
                break;
            }
        }
        a.push_back(res);
        
        sort(a.begin(), a.end());

        res = a.back();
        i64 ans = 0;
        for (i64 x : a) {
            ans += (res - x) / g;
        }
        printf("%lld\n", ans);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney