/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.09.2023 22:52:26
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using Info = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    int n;
    cin >> n;

    vector<Info> sorted;
    for (int i = 0; i < n; i++) {
        string score_board;
        cin >> score_board;
        int win = 0;
        for (int j = 0; j < n; j++) if (i != j && score_board[j] == 'o') {
            --win;
        }
        sorted.emplace_back(win, i);
    }
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n; i++) {
        cout << sorted[i].second + 1 << " \n"[i == n - 1];
    }
}

// ~ Jie ♥ Jenney