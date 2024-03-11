/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.21.2023 14:48:05
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

    int res = 0;
    for (int i = 0; i < n; i++) {
        i64 x;
        scanf("%lld", &x);
        x %= n;
        res += x;
        if (res >= n) {
            res -= n;
        }
    }

    puts(res == 0 ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}