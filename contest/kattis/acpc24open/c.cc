/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 13:53:10
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work() {
    int n, p;
    cin >> n >> p;

    vector a(n, vector<int>(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> a[i][j];
        }
    }
    set<vector<int>> s;
    for (int j = 0; j < p; j++) {
        set<int> dis;
        for (int i = 0; i < n; i++) {
            dis.insert(a[i][j]);
        }
        if (dis.size() != n) {
            continue;
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        ranges::sort(ord, [&](int x, int y) {
            return a[x][j] < a[y][j];
        });
        s.insert(ord);
    }

    cout << s.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie