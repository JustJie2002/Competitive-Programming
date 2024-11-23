/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 20:34:17
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    string s;
    cin >> s;
    int n = s.size();

    string t;
    t += s[0];
    bool good = true;
    bool eq = true;
    for (int i = 1; i < n; i++) {
        if (good) {
            if (s[i] >= t.back()) {
                t += s[i];
            } else {
                good = false;
                t += s[i];
            }
        } else {
            if (!eq) {
                t += t.back();
            } else if (s[i] <= t.back()) {
                t += s[i];
            } else {
                eq = false;
                t += t.back();
            }
        }
    }
    cout << t << "\n";
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

// ~ Just Jie