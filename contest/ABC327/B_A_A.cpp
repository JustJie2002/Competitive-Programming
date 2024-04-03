/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.05.2023 07:13:26
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
    i64 N;
    scanf("%lld", &N);

    for (i64 a = 1; a <= 15; a++) {
        i64 p = 1;
        for (int i = 0; i < a; i++) {
            p *= a;
        }
        if (p == N) {
            printf("%lld\n", a);
            return 0;
        }
    }

    puts("-1");
}

// ~ Jie ♥ Jenney