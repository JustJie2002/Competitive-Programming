/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.18.2023 12:00:57
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

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};

int main() {
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);

    vector mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    pair<int, int> cur = {0, 0};
    map<int, vector<int>> e;
    map<int, vector<pair<int, int>>> pos;
    vector<vector<bool>> vis(n, vector<bool>(m));
    int dir = 0;
    do {
        int op = min({cur.first, cur.second, n - 1 - cur.first, m - 1 - cur.second});
        e[op].push_back(mat[cur.first][cur.second]);
        pos[op].push_back(cur);
        vis[cur.first][cur.second] = 1;
        auto new_cur = make_pair(cur.first + di[dir], cur.second + dj[dir]);
        if (0 <= new_cur.first && new_cur.first < n && 0 <= new_cur.second && new_cur.second < m && !vis[new_cur.first][new_cur.second]) {
            cur.swap(new_cur);
        } else {
            dir++;
            dir %= 4;
            new_cur = make_pair(cur.first + di[dir], cur.second + dj[dir]);
            cur.swap(new_cur);
        }
    } while (!vis[cur.first][cur.second]);

    vector<vector<int>> new_mat(n, vector<int>(m));
    for (auto &[k, v] : e) {
        int o = v.size();
        int nr = r % o;
        rotate(v.begin(), v.begin() + nr, v.end());
        for (int x = 0; x < o; x++) {
            auto& [i, j] = pos[k][x];
            new_mat[i][j] = v[x];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", new_mat[i][j]);
        }
        printf("\n");
    }
}

// ~ Jie ♥ Jenney