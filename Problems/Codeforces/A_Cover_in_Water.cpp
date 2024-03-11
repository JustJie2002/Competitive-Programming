/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.27.2023 00:11:04
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

void workout(int tc) {
    int n;
    scanf("%d", &n);
    auto s = nxt();

    vector<int> pos;
    pos.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            pos.push_back(i);
        }
    }
    pos.push_back(n);

    int m = pos.size();

    int ans = 0;
    for (int i = 1; i < m; i++) {
        int sz = pos[i] - pos[i - 1] - 1;
        if (sz <= 2) {
            ans += sz;
        } else {
            ans = 2;
            break;
        }
    }

    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney