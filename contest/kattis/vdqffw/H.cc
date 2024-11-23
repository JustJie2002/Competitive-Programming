/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.20.2024 13:21:22
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr i64 inf = i64(1e13) + 10;

void work() {
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<i64> sum = a;
    vector<int> mark(n);
    vector<int> sz(n);
    vector<int> L(n), R(n);
    const auto good = [&](i64 s) {
        for (int i = 0; i < n; i++) {
            L[i] = R[i] = i;
            sz[i] = 1;
            mark[i] = 0;
            sum[i] = a[i];
        }

        auto nex = [&](int i) {
            int x = (R[i] + 1);
            if (x >= n) {
                x -= n;
            }
            return x;
        };
        auto pre = [&](int i) {
            int x = (L[i] - 1 + n);
            if (x >= n) {
                x -= n;
            }
            return x;
        };

        int cur = 0;
        while (mark[cur] == 0) {
            if (sum[cur] <= s) {
                mark[cur] = 1;
                while (sz[cur] < n) {
                    int r = nex(cur);
                    if (mark[r] == 1 || sum[r] <= s + sum[cur]) {
                        sum[cur] += sum[r];
                        int rt = R[r];
                        R[cur] = rt;
                        L[rt] = L[cur];
                        sz[cur] += sz[rt];
                        sz[rt] = sz[cur];
                        sum[rt] = sum[cur];
                        mark[rt] = 1;
                        continue;
                    }
                    int l = pre(cur);
                    if (mark[l] == 1 || sum[l] <= s + sum[cur]) {
                        sum[cur] += sum[l];
                        int lt = L[l];
                        L[cur] = lt;
                        R[lt] = R[cur];
                        sz[cur] += sz[l];
                        sz[lt] = sz[cur];
                        sum[lt] = sum[cur];
                        mark[lt] = 1;
                        continue;
                    }
                    break;
                }

                if (sz[cur] < n) {
                    cur = nex(cur);
                } else {
                    return true;
                }
            } else {
                mark[cur] = -1;
                cur = nex(cur);
            }
        }
        return false;
    };

    i64 lo = 0, hi = *max_element(a.begin(), a.end());
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if (good(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << hi << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie