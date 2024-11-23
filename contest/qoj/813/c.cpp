/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.07.2024 22:14:08
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

constexpr int LIM = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    int phi[LIM] {};
    i64 cur = 1;
    int cnt = 0;
    vector<int> primes;
    for (int i = 2; i < LIM; i++) {
        if (phi[i] == 0) {
            phi[i] = i;
            if (cur > n / i) {
                break;
            }
            cnt++;
            cur = cur * i;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p >= LIM) {
                break;
            }
            phi[i * p] = p;
            if (phi[i] == p) {
                break;
            }
        }
    }

    i64 ans = 0;
    for (int mask = 1; mask < (1 << cnt); mask++) {
        i64 l = 1;
        for (int i = 0; i < cnt; i++) {
            if (mask & (1 << i)) {
                l *= primes[i];
            }
        }
        i64 res = cur / l;
        if (__builtin_popcount(mask) & 1) {
            ans += res;
        } else {
            ans -= res;
        }
    }

    i64 g = gcd(ans, cur);
    ans /= g;
    cur /= g;
    cout << ans << "/" << cur << "\n";
}

// ~ Just Jie