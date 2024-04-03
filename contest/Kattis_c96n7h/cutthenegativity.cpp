/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 20:25:27
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;
using Pair = pair<int, int>;

constexpr int N = 101;

int w[N][N];

int main() {
    int n;
    scanf("%d", &n);

    vector<Pair> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
            if (w[i][j] != -1) {
                res.emplace_back(i, j);
            }
        }
    }

    printf("%zu\n", res.size());
    for (const auto& [i, j] : res) {
        printf("%d %d %d\n", i + 1, j + 1, w[i][j]);
    }
}

// ~ Just Jie