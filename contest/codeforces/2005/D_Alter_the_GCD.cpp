/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.15.2024 03:57:37
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

namespace reader {
template<typename T, typename U> pair<T, U>& operator--(pair<T, U>& p) { p.first--; p.second--; return p; }
template<typename T, typename U> pair<T, U>& operator++(pair<T, U>& p) { p.first++; p.second++; return p; }
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){ is >> p.first >> p.second; return is; }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.first << " " << p.second; return os; }
template<typename T> vector<T>& operator--(vector<T> &a) { for (auto& x : a) x--; return a; }
template<typename T> vector<T>& operator++(vector<T> &a) { for (auto& x : a) x++; return a; }
template<typename T> istream& operator>>(istream& is, vector<T> &a) { for (auto& x : a) is >> x; return is;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& a) { for (int x : a) os << x << " "; return os; }
};
using namespace reader;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

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

void chmin(int& a, int b) {
    if (b < a) {
        a = b;
    }
}

void work(int tc) {
    int n;
    // cin >> n;
    n = 166666;

    vector<int> a(n), b(n);
    // cin >> a >> b;
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = 735134400;
    }

    vector<int> pre_a(n, 1), suf_a(n, 1);
    vector<int> pre_b(n, 1), suf_b(n, 1);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pre_a[i] = a[i];
        } else {
            pre_a[i] = gcd(pre_a[i - 1], a[i]);
        }
        if (pre_a[i] == 1) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pre_b[i] = b[i];
        } else {
            pre_b[i] = gcd(pre_b[i - 1], b[i]);
        }
        if (pre_b[i] == 1) {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suf_a[i] = a[i];
        } else {
            suf_a[i] = gcd(suf_a[i + 1], a[i]);
        }
        if (suf_a[i] == 1) {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suf_b[i] = b[i];
        } else {
            suf_b[i] = gcd(suf_b[i + 1], b[i]);
        }
        if (suf_b[i] == 1) {
            break;
        }
    }

    const auto my_swap = [&](int L, int R, int b_g, int a_g) -> int {
        if (L != 0) {
            a_g = gcd(a_g, pre_a[L - 1]);
            b_g = gcd(b_g, pre_b[L - 1]);
        }
        if (R != n - 1) {
            a_g = gcd(a_g, suf_a[R + 1]);
            b_g = gcd(b_g, suf_b[R + 1]);
        }
        return a_g + b_g;
    };

    vector<int> next_a(n + 1, n), next_b(n + 1, n);
    next_a[n - 1] = next_b[n - 1] = n - 1;
    stack<int> stk_a, stk_b;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk_a.empty() && suf_a[stk_a.top()] == suf_a[i]) {
            stk_a.pop();
        }
        if (!stk_a.empty()) {
            next_a[i] = stk_a.top() - 1;
        }
        stk_a.push(i);
        while (!stk_b.empty() && suf_b[stk_b.top()] == suf_b[i]) {
            stk_b.pop();
        }
        if (!stk_b.empty()) {
            next_b[i] = stk_b.top() - 1;
        }
        stk_b.push(i);
    }

    SparseTable<int> rmq_a(a, [&](int x, int y) { return gcd(x, y); });
    SparseTable<int> rmq_b(b, [&](int x, int y) { return gcd(x, y); });

    const auto get_next = [&](int i, int j, int g, const SparseTable<int>& rmq) {
        if (rmq.get(i, n - 1) == g) {
            return n - 1;
        }
        int lo = j, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (rmq.get(i, mid) == g) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    };

    i64 max_g = 2;
    i64 count = 0;
    for (int i = 0; i < n; i++) {
        int a_g = a[i];
        int b_g = b[i];
        int j = i;
        while (j < n) {
            if (a_g != 1 && a_g != a[j]) {
                a_g = gcd(a_g, a[j]);
            }
            if (b_g != 1 && b_g != b[j]) {
                b_g = gcd(b_g, b[j]);
            }
            int new_g = my_swap(i, j, a_g, b_g);
            int nex = next_a[j + 1];
            chmin(nex, next_b[j + 1]);
            chmin(nex, get_next(i, j, a_g, rmq_a));
            chmin(nex, get_next(i, j, b_g, rmq_b));
            if (new_g > max_g) {
                max_g = new_g;
                count = nex - j;
                if (nex == j) {
                    count++;
                }
            } else if (new_g == max_g) {
                count += nex - j;
                if (nex == j) {
                    count++;
                }
            }
            if (nex == j) {
                j++;
            } else {
                j = nex;
            }
        }
    }

    cout << max_g << " " << count << "\n";
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