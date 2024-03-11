/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 11:11:04
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
    auto s = nxt();
    int n = s.size();

    auto t = s;
    array<int, 2> cnt {};
    for (int i = 0; i < n; i++) {
        int par = s[i] - '0';
        cnt[par]++;
    }

    int ans = n;
    auto cur = cnt;
    for (int i = n - 1; i >= 0; i--) {
        if (cur[0] <= cnt[1] && cur[1] <= cnt[0]) {
            ans = n - 1 - i;
            break;
        }
        cur[s[i] - '0']--;
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