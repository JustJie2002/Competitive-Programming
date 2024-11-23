/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 09.28.2024 11:41:34
*********************************************/

#ifdef BROKEN_CODE
#include <bits/LC_parser.h>
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Point = array<int, 2>;

int findMaximumDistance(vector<string> grid) {
    int n = grid.size();
    int m = grid[0].size();
    Point start;
    Point end;
    vector<Point> obs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'E') {
                end = {i, j};
            } else if (grid[i][j] == '*') {
                obs.push_back({i, j});
            }
        }
    }

    int lo = 1, hi = n * m;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (test(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
}

#ifdef BROKEN_CODE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    exec(&Solution::LoveJenney); // CHANGE FOR PROBLEM
}
#endif

// ~ JustJie