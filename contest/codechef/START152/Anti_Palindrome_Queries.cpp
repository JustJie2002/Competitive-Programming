/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.18.2024 17:13:14
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using Info = array<int, 2>;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

constexpr int N = 3;

void work(int tc) {
    int n, Q;
    cin >> n >> Q;

    vector<vector<int>> pos(N);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        pos[x].push_back(i);
    }

    auto get = [&](int L, int R, int x) -> int {
        if (pos[x].empty()) {
            return 0;
        }
        auto upper = int(ranges::upper_bound(pos[x], R) - pos[x].begin());
        auto lower = int(ranges::lower_bound(pos[x], L) - pos[x].begin());
        return upper - lower;
    };

    for (; Q--; ) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        int siz = R - L + 1;
        if (siz & 1) {
            cout << "No\n";
            continue;
        }
        int cnt[N] {};
        for (int i = 0; i < N; i++) {
            cnt[i] = get(L, R, i);
        }
        sort(cnt, cnt + N);
        reverse(cnt, cnt + N);
        int e = siz / 2, o = siz / 2;
        for (int i = 0; i < N; i++) {
            if (e > o) {
                e -= cnt[i];
            } else {
                o -= cnt[i];
            }
        }

        cout << (min(e, o) == 0 ? "Yes" : "No") << "\n";
    }
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