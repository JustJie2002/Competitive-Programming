/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.30.2024 19:50:51
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

constexpr int A = 26;

void work(int tc) {
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    const auto get_freq = [&](const string& s) {
        array<int, A> freq {};
        for (auto c : s) {
            freq[c - 'a']++;
        }
        return freq;
    };

    auto afreq = get_freq(a);
    auto bfreq = get_freq(b);
    for (int x = 0; x < A; x++) {
        if (afreq[x] < bfreq[x]) {
            cout << "NO\n";
            return;
        }
        int ex = afreq[x] - bfreq[x];
        if (ex % k != 0 || (ex > 0 && x == A - 1)) {
            cout << "NO\n";
            return;
        }
        if (x + 1 < A) {
            afreq[x + 1] += ex;
        }
    }
    cout << "YES\n";
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

// ~ Just Jie