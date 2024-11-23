/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.15.2024 03:32:29
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

const string V = "aeiou";

void work(int tc) {
    int n;
    cin >> n;

    int cnt[5] {};
    for (int i = 0; i < n; i++) {
        cnt[i % 5]++;
    }

    for (int i = 0; i < 5; i++) {
        cout << string(cnt[i], V[i]);
    }
    cout << '\n';
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