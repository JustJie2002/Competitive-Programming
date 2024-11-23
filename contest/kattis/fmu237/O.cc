/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 16:24:10
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

constexpr int inf = int(1e9) + 5;

void work() {
    int n, k;
    cin >> n >> k;

    vector<Info> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i][0];
        p[i][1] = i;
    }
    p.push_back({0, -1});

    sort(p.begin(), p.end());

    int start = 0;
    while (p[start] != Info {0, -1}) {
        start++;
    }

    vector<int> dis(n + 1, inf);
    queue<Info> q;
    q.push({start, 1});
    dis[start] = 0;
    while (!q.empty()) {
        auto [u, siz] = q.front();
        q.pop();

        int big = siz;
        int L = u, R = u;
        int cnt = 0;
        do {
            while (L >= 0 && p[u][0] - big <= p[L][0]) {
                L--;
            }
            while (R <= n && p[u][0] + big >= p[R][0]) {
                R++;
            }
            int used = 0;
            for (int i = L + 1; i < R && used < k; i++) {
                if (i == start) {
                    continue;
                }
                if (i == u) {
                    used++;
                    continue;
                }
                used++;
                if (dis[i] == inf) {
                    dis[i] = dis[u] + 1 + cnt;
                    q.push({i, big});
                }
            }
            cnt++;
            big *= 2;
        } while (R - L - 1 - int(u == start) <= k && (R <= n || L >= 0));

        int small = siz;
        L = u, R = u;
        while (L >= 0 && p[u][0] - small <= p[L][0]) {
            L--;
        }
        while (R < n && p[u][0] + small >= p[R][0]) {
            R++;
        }
        L++, R--;
        cnt = 0;
        while (small > 1) {
            small /= 2;
            cnt++;
            while (L >= 0 && p[u][0] - small > p[L][0]) {
                L++;
            }
            while (R < n && p[u][0] + small < p[R][0]) {
                R--;
            }
            int used = 0;
            for (int i = L; i < R + 1 && used < k; i++) {
                if (i == u || i == start) {
                    continue;
                }
                used++;
                if (dis[i] == inf) {
                    dis[i] = dis[u] + 1 + cnt;
                    q.push({i, small});
                }
            }
        }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n + 1; i++) {
        if (i == start) {
            continue;
        }
        if (dis[i] == inf) {
            continue;
        }
        ans[p[i][1]] = dis[i];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie