/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.12.2023 21:41:31
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
    int n, m;
    scanf("%d%d", &n, &m);
    auto s = nxt();

    int a = 0, b = 0, req = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            a = b = 0;
        } else if (s[i] == '1') {
            if (a == m && b == req) {
                req++;
                b++;
            } else if (a == m) {
                b++;
            } else {
                a++;
            }
        } else {
            if (b == req) {
                req++;
            }
            b++;
        }
    }

    printf("%d\n", req);
}

// ~ Jie ♥ Jenney