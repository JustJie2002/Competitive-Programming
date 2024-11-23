/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.05.2024 16:28:07
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Point = array<int, 2>;

constexpr int N = 101;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    vector<Point> p;
    Point w;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                w = {i, j};
            } else if (s[i][j] != '.') {
                p.push_back({i, j});
            }
        }
    }

    int siz = p.size();
    if (siz == 1) {
        cout << 1 << "\n";
        return 0;
    }

    bitset<N> st;
    const auto get = [&](int i, int j) {
        return i * m + j;
    };
}

// ~ JustJie