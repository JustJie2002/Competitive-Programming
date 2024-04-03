/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.16.2023 21:22:14
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;

constexpr int B = 31;

int bit(int mask, int nth) {
    return mask >> nth & 1;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<int> vis(n), ans;
    for (int b = B; b >= 0; b--) {
        vector<int> good, bad;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && bit(a[i], b)) {
                good.push_back(i);
            } else {
                bad.push_back(i);
            }
        }

        if (good.size() >= 2) {
            swap(ans, good);
            for (int i : bad) {
                vis[i] = true;
            }
        }
    }

    if (ans.size() < 2) {
        puts("1 2");
    } else {
        printf("%d %d", ans[0] + 1, ans[1] + 1);
    }
}