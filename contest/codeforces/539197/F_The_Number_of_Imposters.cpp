/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.30.2024 22:42:52
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

void work(int tc) {
    int n, m;
    cin >> n >> m;

    vector<vector<Info>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        string p;
        cin >> p;
        int w = int(p == "imposter");
        g[u].emplace_back(v, w);
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

// ~ Just Jie