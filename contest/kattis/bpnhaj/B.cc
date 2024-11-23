/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:06:23
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

const string V = "aeiou";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    int ans = 0;
    for (char c : s) {
        c = tolower(c);
        if (V.find(c) != string::npos) {
            ans++;
        }
    }
    cout << ans << "\n";
}

// ~ JustJie