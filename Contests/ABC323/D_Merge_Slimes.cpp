/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.09.2023 23:12:05
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using Pair = pair<i64, i64>;

constexpr int MAX_BIT = 48;

int BIT(i64 mask, int nth) {
    return mask & (1LL << nth);
}

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    int n;
    cin >> n;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    for (int i = 0; i < n; i++) {
        i64 sz, f;
        cin >> sz >> f;
        pq.emplace(sz, f);
    }

    int res = 0;
    while (!pq.empty()) {
        auto [sz, f] = pq.top();
        pq.pop();

        while (!pq.empty() && pq.top().first == sz) {
            f += pq.top().second;
            pq.pop();
        }

        if (f == 1) {
            res++;
            continue;
        }

        for (int b = 0; b < MAX_BIT; b++) {
            if ((1LL << b) > f) {
                break;
            }
            if (BIT(f, b)) {
                pq.emplace(sz * (1LL << b), 1);
            }
        }
    }

    cout << res << "\n";
}

// ~ Jie ♥ Jenney