/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.16.2024 21:00:18
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

int main() {
    int n;
    i64 k;
    scanf("%d%lld", &n, &k);

    map<i64, int> freq;
    for (int i = 0; i < n; i++) {
        i64 x;
        scanf("%lld", &x);
        freq[x]++;
    }

    i64 ans = 0;
    i64 extra = 0;
    for (auto it = prev(freq.end()); it != freq.begin(); it--) {
        const auto& [x, f] = *it;
        i64 w = prev(it)->first;
        i64 d = x - w;
        i64 can_use = extra / f;
        if (can_use >= d) {
            extra = 1LL * (can_use - d) * f + (extra % f);
        } else {
            d -= can_use;
            i64 need = 1LL * f * d;
            // i64 cnt = (need + k - 1) / k;
            i64 l = 
            ans += cnt;
            i64 used = cnt * k;
            extra = used - need;
        }
        freq[w] += f;
    }

    printf("%lld\n", ans);
}

// ~ Just Jie