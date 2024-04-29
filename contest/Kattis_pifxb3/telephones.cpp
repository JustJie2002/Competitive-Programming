/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.16.2024 00:12:51
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

void work(int n, int m) {
    map<int, int> events;
    bool has_zero = false;
    vector<array<int, 2>> seg(n);
    for (int i = 0; i < n; i++) {
        int _;
        scanf("%d%d%d%d", &_, &_, &seg[i][0], &seg[i][1]);
        seg[i][1] += seg[i][0] - 1;
    }

    for (int i = 0; i < m; i++) {
        int st, dur;
        scanf("%d%d", &st, &dur);
        int end = st + dur - 1;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int s = max(st, seg[j][0]);
            int e = min(end, seg[j][1]);
            if (s <= e) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    int n, m;
    while ((scanf("%d%d", &n, &m)) && n + m > 0) {
        work(n, m);
    }
}

// ~ Just Jie