/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.12.2023 11:03:02
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAXN = 1e6 + 1;

vector<int> minp;
vector<bool> is_prime;

void init() {
    minp.resize(MAXN);
    is_prime.resize(MAXN, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            minp[i] = i;
            for (i64 j = 1LL * i * i; j < MAXN; j += i) {
                minp[j] = i;
                is_prime[j] = false;
            }
        }
    }
}

void work() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> freq;
    for (int x : a) {
        while (x != 1) {
            int mp = minp[x];
            freq[mp]++;
            x /= mp;
        }
    }

    for (auto& [_, f] : freq) {
        if (f % n) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
#ifndef JIE_LOCAL
    cin.tie(NULL);
#endif

    init();

    int T;
    cin >> T;
    for (int t = 1; T--; t++) {
        work();
    }
}

// ~ Jie ♥ Jenney