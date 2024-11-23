/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.07.2024 13:17:26
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

template <typename T>
struct PSum {
    int n;
    vector<T> pre;

    PSum(int _n): n(_n), pre(n + 1) {}
    PSum(const vector<T> &init): n(init.size()), pre(n + 1) {
        for (int i = 0; i < n; i++) {
            pre[i + 1] = init[i];
        }
    }

    void work() {
        for (int i = 0; i < n; i++) {
            pre[i + 1] += pre[i];
        }
    }

    // set, get
    T& operator[](int i) {
        assert(0 <= i && i <= n);
        return pre[i];
    }

    // sum between [L, R] inclusive both sides
    T get(int L, int R) const {
        assert(0 <= L && L < n);
        assert(0 <= R && R < n);
        assert(L <= R);
        return pre[R + 1] - pre[L];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {1, 2, 3};
    PSum<int> pre(a);
    pre.work();
    int n = 3;

    
}

// ~ Just Jie