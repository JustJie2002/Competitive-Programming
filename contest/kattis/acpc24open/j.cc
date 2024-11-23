/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 16:02:02
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 101, D = 8;
constexpr long double inf64 = 1e17 + 10, EPS = 1e-8;
constexpr int di[D] {-1, 0, 1, 0, -1, -1, 1, 1};
constexpr int dj[D] {0, -1, 0, 1, -1, 1, -1, 1};
constexpr int dist[D] {100, 100, 100, 100, 150, 150, 150, 150};

int h[N][N];
int bt[N][N][D];
long double cur[N][N];
long double dis[N][N];
int speed[N][N];

using Info = tuple<long double, int, int, int>;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

void work() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
            speed[i][j] = 0;
            dis[i][j] = inf64;
            for (int d = 0; d < D; d++) {
                bt[i][j][d] = 0;
            }
        }
    }

    dis[0][0] = 0;
    priority_queue<Info, vector<Info>, greater<Info>> pq;
    pq.push({0, 0, 0, 0});

    auto add_track = [&](int r, int c, int nr, int nc) {
        int dc = nc - c;
        int dr = nr - r;
        if (dc != 0 && dr != 0) {
            int wr = abs(dr);
            int wc = abs(dc);
            assert(wr % wc == 0);
        }
        bool inside = false;
        for (int d = 0; d < D; d++) {
            if (di[d] == dr && dj[d] == dc) {
                bt[r][c][d] = 1;
                inside = true;
                break;
            }
        }
        assert(inside);
    };

    int b;
    cin >> b;
    for (int i = 0; i < b; i++) {
        int r, c;
        cin >> r >> c;
        int nr, nc;
        cin >> nr >> nc;
        add_track(r, c, nr, nc);
    }

    auto in_bound = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    };

    while (!pq.empty()) {
        auto [t, s, i, j] = pq.top();
        pq.pop();

        for (int d = 0; d < D; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (!in_bound(ni, nj)) {
                continue;
            }
            int new_speed = s + (h[i][j] - h[ni][nj]);
            if (bt[i][j][d]) {
                new_speed *= 2;
            }
            new_speed = min(new_speed, 2000);
            if (new_speed <= 0) {
                continue;
            }
            long double new_time = t + 1. * dist[d] / new_speed;
            int both = 0;
            if (new_speed > speed[ni][nj]) {
                speed[ni][nj] = new_speed;
                both++;
            }
            if (new_time - cur[ni][nj] < EPS) {
                dis[ni][nj] = new_time;
                both++;
            }
            if (both > 0) {
                pq.push({new_time, new_speed, ni, nj});
                if (both == 2) {
                    cur[ni][nj] = new_time;
                }
            }
        }
    }
    assert(fabs(dis[n - 1][m - 1] - inf64) > EPS);
    cout << fixed << setprecision(8) << dis[n - 1][m - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie