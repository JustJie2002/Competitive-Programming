/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.05.2024 23:44:59
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 3>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<Info> a(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;

    }
}

/*
2 5 imposter
4 3 crewmate
4 6 imposter
6 5 crewmate
6 7 crewmate
5 4 imposter

we can tell that 3 is imposter because we are crewmate
we can tell that 4 is also imposter because 3 is imposter and they're lying
we can tell that 6 is crewmate, 
*/

// ~ Just Jie