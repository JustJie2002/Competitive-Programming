/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 19:00:50
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
using Pair = pair<int, int>;

void workout(int tc) {
    int n, m;
    scanf("%d%d", &n, &m);

    vector board(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    auto norm = [&](int x, int mod) -> int {
        if (x >= mod) x -= mod;
        return x;
    };

    vector can_up(n, vector<bool>(m));
    vector can_down(n, vector<bool>(m));
    vector can_right(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // as long as the current position is empty
            can_up[i][j] = (board[i][j] == 0);
            
            // as long as there's no rock in the next position and the next next position
            can_down[i][j] = (board[i][j] == 0);

            can_down[i][j] = (board[norm(i + 1, n)][j] == 0);
            can_down[i][j] = (board[norm(i + 2, n)][j] == 0);

            // as long as the next position is fine
            can_right[i][j] = (board[i][j] == 0);
            can_right[i][j] = (board[norm(i + 1, n)][norm(j + 1, n)] == 0);
            can_right[i][j] = (j < m - 1);
        }
    }

    queue<Pair> q;
    vector went(n, vector<bool>(m));

    int t = 0;
    auto enqueue = [&](int r, int c) -> void {
        if (!went[r][c]) {
            q.emplace(r, c);
            went[r][c] = true;
        }
    };

    enqueue(0, 0);

    while (!q.empty()) {
        int Q = q.size();
        while (Q--) {
            auto [r, c] = q.front(); q.pop();

            if (r == n - 1 && c == m - 1) {
                printf("%d\n", t + 1);
                return;
            }

            int pr = (r + t) % n;
            // if (pr < 0) pr += n;
            if (can_down[pr][c]) {
                enqueue(norm(r + 2, n), c);
            }
            if (can_right[pr][c]) {
                enqueue(norm(r + 1, n), c + 1);
            }
            if (can_up[pr][c]) {
                enqueue(norm(r + n - 1, n), c);
            }
        }
        t++;
    }

    puts("-1");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie