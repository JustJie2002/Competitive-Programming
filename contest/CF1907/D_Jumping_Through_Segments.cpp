/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.05.2023 12:00:04
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
using Segment = pair<int, int>;

#define f   first
#define s   second

constexpr int inf = 1e9 + 5;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<Segment> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].f, &a[i].s);
    }

    auto sim = [&](int k) {
        int u = 0;
        for (const auto& [l, r] : a) {
            u += k;
            u = min(u, r);
            if (u < l) {
                return false;
            }
        }
        return true;
    };

    int lo = 0, hi = inf, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (sim(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    printf("%d\n", hi);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney