/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.03.2024 15:57:21
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

constexpr int inf = 1e9 + 5;

int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    int k;
    scanf("%d", &k);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    a.push_back(l);

    auto good = [&](int cutoff) -> int {
        int p = 0;
        int cuts = 0;
        int res = 0;
        for (int x : a) {
            res += x - p;
            if (res >= cutoff) {
                cuts++;
                res = 0;
            }
            p = x;
        }
        if (res < cutoff) {
            cuts--;
        }
        return cuts >= k;
    };

    auto b = std::binary_search()

    int lo = 1, hi = inf, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (good(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
}

// ~ Just Jie