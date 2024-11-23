/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.07.2024 23:22:13
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 2);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    a[n + 1] = a[n] ^ 1;

    int p = a[1];
    int s = 1;
    int cnt = 0;
    vector<string> good, bad;
    for (int i = 1; i < n + 2; i++) {
        if (a[i] == p) {
            cnt++;
        } else {
            if (s == i - 1) {
                string t = to_string(s);
                if (p == 0) {
                    good.push_back(t);
                } else {
                    bad.push_back(t);
                }
            } else {
                string t = to_string(s) + "-" + to_string(i - 1);
                if (p == 0) {
                    good.push_back(t);
                } else {
                    bad.push_back(t);
                }
            }
            s = i;
            cnt = 1;
            p = a[i];
        }
    }

    cout << "Errors: ";
    int sz = bad.size();
    for (int i = 0; i < sz; i++) {
        cout << bad[i];
        if (i == sz - 1) {
            cout << "\n";
        } else if (i == sz - 2) {
            cout << " and ";
        } else {
            cout << ", ";
        }
    }
    cout << "Correct: ";
    sz = good.size();
    for (int i = 0; i < sz; i++) {
        cout << good[i];
        if (i == sz - 1) {
            cout << "\n";
        } else if (i == sz - 2) {
            cout << " and ";
        } else {
            cout << ", ";
        }
    }
}

// ~ Just Jie