/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.05.2023 00:12:32
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

int main() {
    int n, Q;
    scanf("%d%d", &n, &Q);

    auto s = nxt();

    for (; Q--; ) {
        int x, y, l, r;
        scanf("%d%d%d%d", &x, &y, &l, &r);

        // suppose we reversed l to r
    }
}

// ~ Jie ♥ Jenney