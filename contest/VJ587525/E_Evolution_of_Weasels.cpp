/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.16.2023 02:46:55
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void work() {
    string s, t;
    cin >> s >> t;

    auto get = [&](string s) -> pair<int, string> {
        int op = 0;
        string t;
        for (char c : s) {
            if (c == 'B') {
                op ^= 1;
            } else if (!t.empty() && t.back() == c) {
                t.pop_back();
            } else {
                t += c;
            }
        }
        return make_pair(op, t);
    };

    cout << (get(s) == get(t) ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work();
    }
}

// ~ Jie ♥ Jenney