/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.09.2023 22:49:21
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    string s;
    cin >> s;
    int n = s.size();

    bool good = true;
    for (int i = 1; i < n; i += 2) {
        good &= (s[i] == '0');
    }

    cout << (good ? "Yes" : "No") << "\n";
}

// ~ Jie ♥ Jenney