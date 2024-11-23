/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.28.2024 22:34:29
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

constexpr int D[] = {-1, 0, +1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d;
    cin >> n >> m >> d;

    queue<Info> q;
    vector vis(n, vector<bool>(m));
    auto add = [&](int r, int c) -> void {
        if (0 <= r && r < n && 0 <= c && c < m && !vis[r][c]) {
            q.push({r, c});
            vis[r][c] = 1;
        }
    };

    for (int i = 0; i < d; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        add(r, c);
    }

    int l = 0;
    while (!q.empty()) {
        int Q = q.size();
        while (Q--) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + D[k];
                int nc = c + D[k + 1];
                add(nr, nc);
            }
        }
        l++;
    }

    cout << l << "\n";
}

// ~ Just Jie