/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.20.2024 16:05:38
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Point = array<int, 2>;

void work() {
    int n;
    cin >> n;

    int ans = 4;
    int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
        a = max(a, x - y);
        b = max(b, x + y);
        c = max(c, -x + y);
        d = max(d, -x - y);
    }
    ans += (a + b + c + d + 1);
    if (n > 1) {
        for (int i = 1; i < n; i++) {
            if (p[i][0] - p[i - 1][0] != p[i][1] - p[i - 1][1]) {
                ans--;
                break;
            }
        }
    } else {
        ans--;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie