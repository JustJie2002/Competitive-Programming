/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 15:58:04
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = int(3e5) + 5;

int tr[4 * N];

void init(int p, int l, int r) {
    if (l == r) {
        tr[p] = 1;
        return;
    }
    int m = (l + r) / 2;
    init(2 * p, l, m);
    init(2 * p + 1, m + 1, r);
    tr[p] = tr[2 * p] + tr[2 * p + 1];
}

int range_query(int p, int l, int r, int x, int y) {
    if (l == x && r == y) {
        return tr[p];
    }
    int m = (l + r) / 2;
    int ans = 0;
    if (y <= m) {
        ans += range_query(2 * p, l, m, x, y);
    } else if (x > m) {
        ans += range_query(2 * p + 1, m + 1, r, x, y);
    } else {
        ans += range_query(2 * p, l, m, x, m);
        ans += range_query(2 * p + 1, m + 1, r, m + 1, y);
    }
    return ans;
}

void modify(int p, int l, int r, int x) {
    if (l == r) {
        tr[p] = 0;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) {
        modify(2 * p, l, m, x);
    } else {
        modify(2 * p + 1, m + 1, r, x);
    }
    tr[p] = tr[2 * p] + tr[2 * p + 1];
}

void work() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), 
        [&](int i, int j) {
            return a[i] < a[j];
        });

    int L = 0, R = n - 1;
    i64 ans = 0;
    init(1, 0, n - 1);
    for (int i : ord) {
        int sumL = 0;
        if (0 <= i - 1) {
            sumL = range_query(1, 0, n - 1, 0, i - 1);
        }
        int sumR = 0;
        if (i + 1 <= n - 1) {
            sumR = range_query(1, 0, n - 1, i + 1, n - 1);
        }
        if (sumL <= sumR) {
            ans += sumL;
            L++;
        } else {
            ans += sumR;
            R--;
        }
        modify(1, 0, n - 1, i);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie