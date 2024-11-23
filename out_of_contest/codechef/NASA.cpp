/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.18.2024 21:11:26
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int N = 1 << 15;

vector<int> pal;

void work(int tc) {
    int n;
    cin >> n;

    array<int, N> freq {};
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        for (int p : pal) {
            ans += freq[p ^ x];
        }
    }
    
    cout << ans << "\n";
}

void Init() {
    for (int i = 0; i < N; i++) {
        string s = to_string(i);
        string t(s.rbegin(), s.rend());
        if (s == t) {
            pal.push_back(i);
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