/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.19.2024 10:43:37
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;
using Info = tuple<int, int, int>;

int main() {
    int n;
    scanf("%d", &n);

    vector<Info> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            scanf("%d", &w);
            if (w != -1) {
                edges.push_back({i + 1, j + 1, w});
            }
        }
    }

    printf("%zu\n", edges.size());
    for (const auto& [u, v, w] : edges) {
        printf("%d %d %d\n", u, v, w);
    }
}

// ~ Just Jie