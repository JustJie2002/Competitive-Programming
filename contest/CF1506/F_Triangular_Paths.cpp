/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.31.2024 23:48:25
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
using Point = array<int, 2>;

void workout(int tc) {
    int n;
    scanf("%d", &n);
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &points[i][0]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &points[i][1]);
    }

    sort(points.begin(), points.end());

    auto go = [&](const Point& from, const Point& to) -> i64 {
        const auto& [sr, sc] = from;
        const auto& [er, ec] = to;
        int dr = er - sr;
        int dc = ec - sc;
        int t = sr + sc;
        i64 res = 0;
        if (dr == dc) {
            if (t % 2 == 0) {
                res += dc;
            }
        } else {
            int dd = dr - dc;
            if (t % 2 == 0) {
                res += dd / 2;
            } else {
                res += (dd + 1) / 2;
            }
        }
        return res;
    };

    Point from {1, 1};
    i64 ans = 0;
    for (const auto& point : points) {
        ans += go(from, point);
        from = point;
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