/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.13.2023 02:52:17
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
using Info = pair<i64, i64>;
using Info2 = pair<Info, int>;

int main() {
    i64 x;
    int n;
    scanf("%lld%d", &x, &n);

    vector<vector<i64>> aa(n);
    vector<queue<Info>> store(n);
    priority_queue<Info2, vector<Info2>, greater<Info2>> pq;
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            i64 w;
            scanf("%lld", &w);
            if (w == 0) {
                continue;
            }
            if (!aa[i].empty() && ((w < 0) == (aa[i].back() < 0))) {
                aa[i].back() += w;
            } else {
                aa[i].push_back(w);
            }
        }

        m = aa[i].size();

        if (m == 0) {
            continue;
        }

        int j = 0;
        if (aa[i][0] > 0) {
            x += aa[i][j++];
        }
        bool bad = false;
        Info pre(-1, -1);
        for (; j < m - 1; j += 2) {
            assert(aa[i][j] < 0);
            i64 need_to_tank = abs(aa[i][j]);
            i64 gain = aa[i][j + 1];
            assert(gain > 0);
            i64 profit = gain - need_to_tank;
            if (bad) {
                pre.first = max(pre.first, abs(pre.second) + need_to_tank);
                pre.second += profit;
                if (pre.second > 0) {
                    store[i].push(pre);
                    bad = false;
                }
            } else {
                if (profit < 0) {
                    bad = true;
                    pre.first = need_to_tank;
                    pre.second = profit;
                } else {
                    store[i].emplace(need_to_tank, profit);
                }
            }
        }

        if (!store[i].empty()) {
            pq.emplace(store[i].front(), i);
        }
    }

    i64 ans = x;
    while (!pq.empty()) {
        auto [info, idx] = pq.top();
        pq.pop();
        auto [tank, profit] = info;

        if (x - tank < 0) {
            break;
        }

        ans = max(ans, x += profit);
        store[idx].pop();
        if (!store[idx].empty()) {
            pq.emplace(store[idx].front(), idx);
        }
    }

    printf("%lld\n", ans);
}

// ~ Jie ♥ Jenney