/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.12.2023 10:49:33
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAXN = 3;
int a[MAXN];

void work() {
    for (int i = 0; i < MAXN; i++) {
        cin >> a[i];
    }

    int t = *min_element(a, a + MAXN);

    int cut = 0;
    for (int i = 0; i < MAXN; i++) {
        if (a[i] % t) {
            cut = 4;
            break;
        }
        cut += a[i] / t - 1;
    }

    cout << (cut <= 3 ? "YES" : "NO") << "\n";
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