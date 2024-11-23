/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.13.2024 12:53:38
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

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), 
        [&](int i, int j) {
            return a[i] > a[j];
        });

    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = s.insert(ord[i]).first;
        if (it != s.begin()) {
            ans++;
        }
        if (next(it) != s.end()) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    work();
}

// ~ Just Jie