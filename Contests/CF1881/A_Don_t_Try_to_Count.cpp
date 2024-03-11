/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.12.2023 10:36:02
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void work() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    if (s.find(t) != string:: npos) {
        cout << 0 << "\n";
        return;
    }

    int res = 0;
    do {
        s += s;
        res++;
        if (s.find(t) != string:: npos) {
            cout << res << "\n";
            return;
        }
        n += n;
    } while (n <= 2 * m);

    cout << -1 << "\n";
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