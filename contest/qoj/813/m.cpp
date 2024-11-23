/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 00:19:39
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    string t;
    cin >> t;
    reverse(t.begin(), t.end());
    while (t.size() < 7) {
        t += "0";
    }

    string res;
    int moves = 0;
    for (int i = 0; i < 6; i++) {
        int v = t[i] - '0';
        for (int j = 0; j < 3; j++) {
            if (v & (1 << j)) {
                res += '1';
                if (i <= 2) {
                    moves++;
                }
            } else {
                res += '0';
            }
        }
    }
    res += '0' + (t[6] & 1);

    const auto divmod = [&](int x, int mod) {
        return pair(x / mod, x % mod);
    };

    vector board(3, string(3, '.'));
    for (int i = 9; i < 18; i++) {
        if (res[i - 9] == '1') {
            auto [r, c] = divmod(i - 9, 3);
            board[r][c] = (res[i] == '1' ? 'X' : 'O');
        }
    }

    const auto check_win = [&](char c) -> bool {
        string won = string(3, c);
        for (int i = 0; i < 3; i++) {
            if (board[i] == won) {
                return true;
            }
            string t;
            for (int j = 0; j < 3; j++) {
                t += board[j][i];
            }
            if (t == won) {
                return true;
            }
        }
        string t1, t2;
        for (int i = 0; i < 3; i++) {
            t1 += board[i][i];
            t2 += board[i][3 - i - 1];
        }
        return t1 == won || t2 == won;
    };

    if (check_win('X')) {
        cout << "X wins\n";
    } else if (check_win('O')) {
        cout << "O wins\n";
    } else if (moves == 9) {
        cout << "Cat's\n";
    } else {
        cout << "In progress\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

/*
O wins
X wins
Cat’s
In progress

O wins
X wins
Cat's
In progress
*/

// ~ Just Jie