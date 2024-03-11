/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.09.2023 22:59:21
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using Point = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    int n, m;
    cin >> n >> m;

    vector<Point> points;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        points.emplace_back(p, i);
    }

    sort(points.rbegin(), points.rend());

    vector<int> score(n);
    iota(score.begin(), score.end(), 1);
    vector<string> score_board(n);
    int ma = 0, f = 0;
    for (int i = 0; i < n; i++) {
        cin >> score_board[i];
        for (auto& [p, idx] : points) if (score_board[i][idx] == 'o') {
            score[i] += p;
        }
        if (score[i] == ma) {
            f++;
        } else if (score[i] > ma) {
            ma = score[i];
            f = 1;
        }
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) if (!(score[i] == ma && f == 1)) {
        for (auto& [p, idx] : points) if (score[i] <= ma && score_board[i][idx] == 'x') {
            score[i] += p;
            res[i]++;
        }
    }

    for (int x : res) {
        cout << x << "\n";
    }
}

// ~ Jie ♥ Jenney