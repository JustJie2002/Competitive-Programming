/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.07.2024 22:54:32
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2 - 1; i++) {
            if (s[i] != '|') {
                cout << "fix\n";
                return 0;
            }
            if (s[n - i - 1] != '|') {
                cout << "fix\n";
                return 0;
            }
        }
        cout << (s.substr(n / 2 - 1, 2) == "()" ? "correct" : "fix") << "\n";
    } else {
        cout << "fix\n";
    }
}

// ~ Just Jie