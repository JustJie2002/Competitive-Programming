/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.20.2024 13:30:15
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 5;

void work(int tc) {
    int n;
    cin >> n;

    vector<array<int, N>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    const auto win = [&](const auto& x, const auto& y) {
        int good = 0;;
        for (int k = 0; k < N; k++) {
            if (x[k] < y[k]) {
                good++;
            }
        }
        return good >= 3;
    };

    auto cand = a[0];
    int id = 1;
    for (int i = 1; i < n; i++) {
        if (win(a[i], cand)) {
            cand = a[i];
            id = i + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == id - 1) {
            continue;
        }
        if (!win(cand, a[i])) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << id << "\n";
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