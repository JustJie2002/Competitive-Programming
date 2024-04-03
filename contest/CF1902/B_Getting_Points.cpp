/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.04.2023 23:32:51
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
    i64 n, a, b;
    i64 P;
    scanf("%lld%lld%lld%lld", &n, &P, &a, &b);

    i64 comb = a + 2LL * b;
    i64 t = (n - 1) / 7 + 1;
    i64 need = (P + comb - 1) / comb;
    i64 g = min(t / 2, need);
    P -= g * comb;
    if (P > 0) {
        if (t & 1) {
            P -= comb - b;
            g++;
        }
        if (P > 0) {
            g += (P + a - 1) / a;
        }
    }
    printf("%lld\n", n - g);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney