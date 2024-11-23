/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.17.2024 01:30:42
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int ord(char c) { return c - 'a'; }

void work(int tc) {
    string s;
    cin >> s;
    int n = s.size();

    const auto has = [&](int mask, int nth) {
        return mask & (1 << nth);
    };
    const auto good = [&](int start) {
        for (int i = start; i < n; i += 7) {
            int mask = 0;
            for (int j = i; j < min(n, i + 7); j++) {
                int o = s[j];
                if (has(mask, o)) {
                    return false;
                }
                mask |= (1 << o);
            }
        }
        return true;
    };

    int seen = 0;
    for (int i = 0; i < min(n, 7); i++) {
        int o = ord(s[i]);
        if (!has(seen, o)) {
            seen |= (1 << o);
            if (good(i + 1)) {
                cout << "1\n";
                return;
            }
        } else {
            break;
        }
    }
    cout << "0\n";
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