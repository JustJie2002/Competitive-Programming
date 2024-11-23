/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.17.2024 20:33:29
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int LOWER = 5, UPPER = 10;

bool good[UPPER];

void work(int tc) {
    string s;
    cin >> s;
    int n = s.size();

    reverse(s.begin(), s.end());

    for (int i = 0; i < n - 1; i++) {
        int d = s[i] - '0';
        if (i == 0) {
            if (!good[d]) {
                cout << "NO\n";
                return;
            }
        } else {
            if (!good[(d + 9) % 10]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << (s.back() == '1' ? "YES" : "NO") << "\n";
}

void Init() {
    for (int i = LOWER; i < UPPER; i++) {
        for (int j = LOWER; j < UPPER; j++) {
            int sum = i + j;
            int d = sum % 10;
            good[d] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();
    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work(t);
    }
}

// ~ Just Jie