/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.22.2024 17:49:53
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

// Credit: tourist
template<typename T, class F = function<T(const T&, const T&)>>
struct SparseTable {
    int n;
    vector<vector<T>> st;
    F merge;

    SparseTable(const vector<T>& a, const F& f): merge(f) {
        n = a.size();
        int max_log = 32 - __builtin_clz(n);
        st.resize(max_log);
        st[0] = a;
        for (int lg = 1; lg < max_log; lg++) {
            st[lg].resize(n - (1 << lg) + 1);
            for (int i = 0; i <= n - (1 << lg); i++) {
                st[lg][i] = merge(st[lg - 1][i], st[lg - 1][i + (1 << (lg - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return merge(st[lg][from], st[lg][to - (1 << lg) + 1]);
    }
};

void work(int tc) {
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> e(n + 2);
    for (int i = 0; i < k; i++) {
        int L, R;
        cin >> L >> R;
        e[L]++;
        // e[R + 1]--;
    }
    for (int i = 1; i < n + 2; i++) {
        e[i] += e[i - 1];
    }

    const auto get = [&](int i) -> int {
        return e[i + d - 1] - e[i - 1];
    };

    int rb = 1, rm = 1;
    for (int i = 1; i <= n - d + 1; i++) {
        if (get(i) > get(rb)) {
            rb = i;
        }
        if (get(i) < get(rm)) {
            rm = i;
        }
    }

    cout << rb << " " << rm << "\n";
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

// ~ JustJie