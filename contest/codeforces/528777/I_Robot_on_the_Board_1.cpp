/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 13:44:39
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int x = 1, y = 1;
    int dx = 0, dy = 0;
    int mi_dx = 0, ma_dx = 0;
    int mi_dy = 0, ma_dy = 0;
    for (auto c : s) {
        if (c == 'L') {
            dx--;
        } else if (c == 'R') {
            dx++;
        } else if (c == 'U') {
            dy--;
        } else {
            dy++;
        }
        mi_dx = min(mi_dx, dx);
        ma_dx = max(ma_dx, dx);
        mi_dy = min(mi_dy, dy);
        ma_dy = max(ma_dy, dy);
        if (x + mi_dx <= 0) {
            if (x + 1 + ma_dx > m) {
                break;
            } else {
                x++;
            }
        } else if (x + ma_dx > m) {
            break;
        } else if (y + mi_dy <= 0) {
            if (y + 1 + ma_dy > n) {
                break;
            } else {
                y++;
            }
        } else if (y + ma_dy > n) {
            break;
        }
    }
    cout << y << " " << x << "\n";
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

// ~ Just Jie