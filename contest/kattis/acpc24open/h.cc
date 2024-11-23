/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2024 14:38:57
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> L(n, -1), R(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] > a[stk.top()]) {
            stk.pop();
        }
        if (!stk.empty()) {
            L[i] = stk.top();
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        stk.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[i] > a[stk.top()]) {
            stk.pop();
        }
        if (!stk.empty()) {
            R[i] = stk.top();
        }
        stk.push(i);
    }

    vector<int> ans(n);
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            if (L[i] == -1 && R[i] == -1) {
                ans[i] = -1;
            } else {
                ans[i] = n;
                if (L[i] != -1) {
                    ans[i] = min(ans[i], i - L[i]);
                }
                if (R[i] != -1) {
                    ans[i] = min(ans[i], R[i] - i);
                }
            }
        } else {
            ans[i] = 0;
        }
    }

    for (int x : ans) {
        cout << x << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie