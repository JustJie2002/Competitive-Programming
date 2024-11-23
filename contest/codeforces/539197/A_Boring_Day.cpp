/***************************************************************************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.30.2024 19:31:19
****************************************************************************************************/
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

void work(int tc) {
    int n, L, R;
    cin >> n >> L >> R;

    int cur = 0;
    int ans = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cur += x;
        q.push(x);
        while (cur > R) {
            cur -= q.front();
            q.pop();
        }
        if (cur >= L) {
            ans++;
            while (!q.empty()) {
                q.pop();
            }
            cur = 0;
        }
    }
    cout << ans << "\n";
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