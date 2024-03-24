/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 13:14:19
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

constexpr int inf = 1e9 + 5;

int main() {
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);

    vector aa(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &aa[i][j]);
        }
        sort(aa[i].begin(), aa[i].end());
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        int tot = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            tot += aa[i][j];
            pq.push(aa[i][j]);
        }
        if (tot <= c) {
            c -= tot;
            ans += n;
        } else {
            while (true) {
                int u = pq.top();
                pq.pop();
                if (u > c) {
                    break;
                }
                c -= u;
                ans++;
            }
            break;
        }
    }

    printf("%d\n", ans);
}

// ~ Just Jie