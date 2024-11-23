/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.06.2024 11:57:31
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Point = array<int, 2>;

constexpr int LIM = 100000;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

void work(int tc) {
    int n, d;
    cin >> n >> d;

    vector<Point> p(n);
    map<int, vector<int>> lookup;
    vector<set<int>> adj(10 * n + 10);
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
        // p[i][0] += LIM;
        // p[i][1] += LIM;
        int sum1 = p[i][0] + p[i][1];
        if (lookup.contains(d + sum1)) {
            for (int x : lookup[d + sum1]) {
                adj[i * 10 + 1].insert(x);
                adj[x].insert(i * 10 + 1);
            }
        }
        
        int sum2 = p[i][0] - p[i][1];
        if (lookup.contains(d + sum2)) {
            for (int x : lookup[d + sum2]) {
                adj[i * 10 + 2].insert(x);
                adj[x].insert(i * 10 + 2);
            }
        }
        
        int sum3 = -p[i][0] + p[i][1];
        if (lookup.contains(d + sum3)) {
            for (int x : lookup[d + sum3]) {
                adj[i * 10 + 3].insert(x);
                adj[x].insert(i * 10 + 3);
            }
        }

        int sum4 = -(p[i][0] + p[i][1]);
        if (lookup.contains(d + sum4)) {
            for (int x : lookup[d + sum4]) {
                adj[i * 10 + 4].insert(x);
                adj[x].insert(i * 10 + 4);
            }
        }
        lookup[sum1].push_back(i * 10 + 1);
        lookup[sum2].push_back(i * 10 + 2);
        lookup[sum3].push_back(i * 10 + 3);
        lookup[sum4].push_back(i * 10 + 4);
    }

    // (x - x1) + (y - y1)
    // (x1 - x) + (y - y1)
    // (x - x1) + (y1 - y)
    // (x1 - x) + (y1 - y)

    // (x1 - x2) + (y1 - y2) = d
    // x1 + y1 - (x2 + y2) = d
    // x1 + y1 = d + (x2 + y2)

    for (int i = 0; i < 10 * n + 10; i++) {
        for (int j : adj[i]) {
            for (int k : adj[j]) {
                cout << i << " " << j << " " << k << "\n";
                if (adj[k].contains(i)) {
                    cout << i / 10 + 1 << " " << j / 10 + 1 << " " << k / 10 + 1 << "\n";
                    return;
                }
            }
        }
    }

    cout << "0 0 0\n";
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