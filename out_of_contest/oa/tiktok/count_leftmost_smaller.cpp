/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.14.2024 18:17:10
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<int> stk;
    vector<int> right_smaller(n, n);
    int total_subarray = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[i] <= a[stk.top()]) {
            stk.pop();
        }
        if (stk.empty()) {
            right_smaller[i] = stk.top();
        }
        stk.push(i);
        total_subarray += right_smaller[i] - i; 
    }

    cout << total_subarray << "\n";
}

// ~ JustJie