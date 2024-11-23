/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.19.2024 00:47:39
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

struct SuffixArray {
	int n;
    vector<int> sa, rk, lc;
    // sa[i] - the i'th smallest suffix's beginning index
    // rk[i] - the rank of the suffix starting at index i, where i is in sa array
    // lc[i] - longest common prefix between sa[i] and sa[i + 1]
    SuffixArray(const string &s) {
    	n = s.length();
        sa.resize(n);
        lc.resize(n - 1);
        rk.resize(n);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int a, int b) {return s[a] < s[b];});
        rk[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        int k = 1;
        vector<int> tmp, cnt(n);
        tmp.reserve(n);
        while (rk[sa[n - 1]] < n - 1) {
            tmp.clear();
            for (int i = 0; i < k; ++i)
                tmp.push_back(n - k + i);
            for (auto i : sa)
                if (i >= k)
                    tmp.push_back(i - k);
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; ++i)
                ++cnt[rk[i]];
            for (int i = 1; i < n; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i)
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 
1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
            k *= 2;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            if (rk[i] == 0) {
                j = 0;
            } else {
                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]; )
                    ++j;
                lc[rk[i] - 1] = j;
            }
        }
    }
};

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

constexpr i64 inf = i64(1e15) + 5;

using Info = array<i64, 2>;

void work() {
    string s, t;
    i64 c[2];
    cin >> s >> t;
    for (int i = 0; i < 2; i++) {
        cin >> c[i];
    }

    auto ord = [&](char c) { return c - 'a'; };
    auto good = [&]() {
        int exist = 0;
        for (char c : t) {
            exist |= (1 << ord(c));
        }
        for (char c : s) {
            if (exist >> ord(c) & 1) {
            } else {
                return false;
            }
        }
        return true;
    };

    if (!good()) {
        cout << "Impossible\n";
        return;
    }

    int n = s.size();
    int m = t.size();
    int o = n + m + 1;

    vector<Info> e(n);
    auto update = [&](const string& T, int rev) { // O((N + M) log (N + M))
        SuffixArray SA(T);
        SparseTable<int> rmq(SA.lc, 
            [&](int a, int b) {
                return min(a, b);
            });

        const auto& sa = SA.sa;
        const auto& rk = SA.rk;

        vector<int> L(o), R(o);
        int seen = -1;
        for (int i = 0; i < o; i++) {
            L[i] = seen;
            if (sa[i] < m) {
                seen = i;
            }
        }
        int rseen = -1;
        for (int i = o - 1; i >= 0; i--) {
            R[i] = rseen;
            if (sa[i] < m) {
                rseen = i;
            }
        }

        for (int i = 0; i < n; i++) {
            auto& dis = e[i][rev];
            int cur = m + i + 1;
            int rank = rk[cur];
            dis = 0;
            if (L[rank] != -1) {
                dis = max(dis, (i64) rmq.get(L[rank], rank - 1));
            }
            if (R[rank] != -1) {
                dis = max(dis, (i64) rmq.get(rank, R[rank] - 1));
            }
        }
    };

    update(t + "#" + s, 0);
    reverse(t.begin(), t.end());
    update(t + "#" + s, 1);

    vector<i64> dp(n + 1, inf);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) { // O(N)
        auto& cur = dp[i];
        for (int j = 0; j < 2; j++) {
            i64 jump = e[i][j];
            if (jump == 0) {
                continue;
            }
            assert(i + jump <= n);
            cur = min(cur, dp[i + jump] + c[j]);
        }
    }

    auto ans = dp[0];
    assert(ans != inf);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie