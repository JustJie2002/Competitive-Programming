/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 16:41:46
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

int main() {
    i64 n;
    int m, Q;
    scanf("%lld%d%d", &n, &m, &Q);

    vector<i64> pre, mul, mul_sum;
    if (m > 1) {
        pre.push_back(0LL);
        pre.push_back(1LL);
        while (pre.back() < n) {
            pre.push_back(pre.back() * m);
        }
        int pre_siz = pre.size();
        for (int i = 1; i < pre_siz; i++) {
            pre[i] += pre[i - 1];
        }
        mul.push_back(1LL);
        mul_sum.push_back(2LL);
        for (int i = 1; i < pre_siz; i++) {
            int fa = mul.back();
            mul.push_back(fa * m);
            mul_sum.push_back(mul_sum.back() + mul.back());
        }
    }

    auto depth = [&](i64 p) -> i64 {
        return int(lower_bound(pre.begin(), pre.end(), p) - pre.begin());
    };

    auto jump = [&](i64 p, i64 k) -> i64 {
        return (p + mul[k] - mul_sum[k - 1]) / mul[k];
    };

    // dbg(jump(5, 2));

    auto dis = [&](i64 p, i64 q) {
        i64 pdep = depth(p), qdep = depth(q);
        i64 res = abs(pdep - qdep);
        if (pdep < qdep) {
            q = jump(q, res);
        } else if (qdep < pdep) {
            p = jump(p, res);
        }

        if (p == q) {
            return res;
        }

        i64 lo = 1, hi = pdep, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int p_to = jump(p, mid);
            int q_to = jump(q, mid);
            if (p_to == q_to) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        res += 2LL * hi;
        return res;
    };

    for (; Q--; ) {
        i64 p, q;
        scanf("%lld%lld", &p, &q);
        if (m == 1) {
            printf("%lld\n", abs(p - q));
        } else {
            printf("%lld\n", dis(p, q));
        }
    }
}

// ~ Just Jie