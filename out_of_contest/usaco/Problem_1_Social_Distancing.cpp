/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.01.2024 23:31:57
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
using Segment = array<i64, 2>;

constexpr i64 INF = 1e18 + 10;

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);

    vector<Segment> seg(m);
    for (auto& [a, b] : seg) {
        scanf("%lld%lld", &a, &b);
    }

    sort(seg.begin(), seg.end());

    auto issoke = [&](i64 d) -> bool {
        int ans = 0;
        i64 pre = -d;
        for (const auto& [a, b] : seg) {
            i64 nxt = pre + d;
            i64 mi = max(a, nxt);
            if (mi > b) {
                continue;
            }
            i64 rem = b - mi;
            i64 can_place = rem / d;
            ans += can_place + 1;
            pre = mi + can_place * d;
            if (ans >= n) {
                return true;
            }
        }
        return false;
    };

    i64 lo = 0, hi = INF, mid;
    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (issoke(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", lo);
}

// ~ Just Jie