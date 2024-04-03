/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 18:28:32
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;
using Info = array<int, 2>;

int main() {
    int n, t;
    scanf("%d%d", &n, &t);

    vector<Info> a(n);
    unordered_map<int, int> at_time;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i][0], &a[i][1]);
        at_time[a[i][1]]++;
    }

    sort(a.begin(), a.end(),
        [&](auto&& x, auto&& y) {
            return x[1] < y[1];
        });

    int i = 0, cur_time = 0;
    int fake_time = 0;
    int ans = 0;
    priority_queue<Info> pq;
    priority_queue<int, vector<int>, greater<int>> used;
    // O(N log N)
    while (cur_time < t && i < n) {
        while (i < n && a[i][1] == fake_time) {
            pq.push(a[i]);
            i++;
        }
        while (!pq.empty() && pq.top()[1] < cur_time) {
            if (pq.top()[0] > used.top()) {
                ans -= used.top();
                used.pop();
                ans += pq.top()[0];
                used.push(pq.top()[0]);
            }
            pq.pop();
        }
        if (pq.empty() && i < n) {
            fake_time = a[i][1];
        } else if (!pq.empty()) {
            ans += pq.top()[0];
            used.push(pq.top()[0]);
            pq.pop();
            cur_time++;
            fake_time = max(fake_time, cur_time);
        }
    }
    while (!pq.empty() && pq.top()[1] < cur_time) {
        if (pq.top()[0] > used.top()) {
            ans -= used.top();
            used.pop();
            ans += pq.top()[0];
            used.push(pq.top()[0]);
        }
        pq.pop();
    }

    printf("%d\n", ans);
}

// ~ Just Jie