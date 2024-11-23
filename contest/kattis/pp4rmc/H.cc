/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:39:48
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Point = array<double, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point g;
    cin >> g[0] >> g[1];

    Point a, b;
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];

    const auto dis = [&](const Point& x, const Point& y) {
        return sqrtl((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]));
    };

    cout << fixed << setprecision(6) << "\n";
    if (a[1] <= g[1] && g[1] <= b[1]) {
        if (g[0] <= a[0]) {
            cout << a[0] - g[0] << "\n";
        } else {
            cout << g[0] - b[0] << "\n";
        }
    } else if (b[1] < g[1]) {
        if (g[0] < a[0]) {
            cout << dis(g, Point {a[0], b[1]}) << "\n";
        } else if (g[0] <= b[0]) {
            cout << g[1] - b[1] << "\n";
        } else {
            cout << dis(g, b) << "\n";
        }
    } else {
        assert(g[1] < a[1]);
        if (g[0] < a[0]) {
            cout << dis(g, a) << "\n";
        } else if (g[0] <= b[0]) {
            cout << a[1] - g[1] << "\n";
        } else {
            cout << dis(g, Point {b[0], a[1]}) << "\n";
        }
    }
}

// ~ JustJie