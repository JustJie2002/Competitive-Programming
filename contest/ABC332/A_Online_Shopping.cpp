/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.12.2023 21:36:22
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
    int n, s, k;
    scanf("%d%d%d", &n, &s, &k);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        res += p * q;
    }

    if (res < s) {
        res += k;
    }

    printf("%d\n", res);
}

// ~ Jie ♥ Jenney