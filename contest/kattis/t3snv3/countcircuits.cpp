/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 18:33:29
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Info> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    auto work = [&](int L, int R) {
        int siz = R - L;
        const int TOT = 1 << siz;
        map<Info, int> res;
        for (int msk = 1; msk < TOT; msk++) {
            Info cur {};
            for (int i = 0; i < siz; i++) {
                if (msk & (1 << i)) {
                    cur[0] += v[L + i][0];
                    cur[1] += v[L + i][1];
                }
            }
            res[cur]++;
        }
        return res;
    };
    auto neg = [&](auto p) {
        p[0] = -p[0];
        p[1] = -p[1];
        return p;
    };

    i64 ans = 0;
    if (n <= 20) {
        auto a = work(0, n);
        ans = a[{}];
    } else {
        auto a = work(0, n / 2);
        auto b = work(n / 2, n);
        for (const auto &[p, v] : a) {
            ans += 1LL * v * b[neg(p)];
        }
        ans += a[{}];
        ans += b[{}];
    }

    cout << ans << "\n";
}

// ~ Just Jie