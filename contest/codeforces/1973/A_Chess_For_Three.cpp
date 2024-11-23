/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.18.2024 21:40:22
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void work(int tc) {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b + c) % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    priority_queue<int> pq;
    if (a) pq.push(a);
    if (b) pq.push(b);
    if (c) pq.push(c);
    int ans = 0;
    while (pq.size() >= 2) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        x--, y--;
        if (x) {
            pq.push(x);
        }
        if (y) {
            pq.push(y);
        }
        ans++;
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