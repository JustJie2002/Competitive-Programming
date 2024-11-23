/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 10.12.2024 01:14:16
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

    cout << int(n >= 3 && s.substr(0, 3) == "555") << "\n";
}

// ~ JustJie