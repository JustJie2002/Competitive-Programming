/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 20:03:46
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
using Coordinate = array<i64, 2>;

void work(int tc) {
    printf("Case #%d: ", tc);

    int n, A, B, C, D, x0, y0, M;
    scanf("%d", &n);
    scanf("%d%d%d%d", &A, &B, &C, &D);
    scanf("%d%d", &x0, &y0);
    scanf("%d", &M);

    i64 x = x0;
    i64 y = y0;

    set<Coordinate> points, lookup;
    for (int i = 0; i < n; i++) {
        Coordinate p = {x, y};
        if (!points.contains(p)) {
            points.insert(p);
            lookup.insert({3 * x, 3 * y});
        }
        x = (x * A + B) % M;
        y = (y * C + D) % M;
    }

    vector<Coordinate> apoints(points.begin(), points.end());
    auto issoke = [&](int i, int j, int k) {
        const auto& [x1, y1] = apoints[i];
        const auto& [x2, y2] = apoints[j];
        const auto& [x3, y3] = apoints[k];
        if (x1 == x2 || x2 == x3) {
            return x1 != x2 || x2 != x3;
        }
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1);
    };
    auto get = [&](int i, int j, int k) {
        const auto& [x1, y1] = apoints[i];
        const auto& [x2, y2] = apoints[j];
        const auto& [x3, y3] = apoints[k];
        Coordinate p = {x1 + x2 + x3, y1 + y2 + y3};
        return p;
    };

    n = apoints.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (issoke(i, j, k)) {
                    auto mid = get(i, j, k);
                    if (lookup.contains(mid)) {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie