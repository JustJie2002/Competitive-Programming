/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.12.2023 21:37:51
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
    int k, g, m;
    scanf("%d%d%d", &k, &g, &m);

    int a = 0, b = 0; // a is glass, b is mug
    for (; k--; ) {
        // check if a is full
        if (a == g) {
            a = 0;
        } else if (b == 0) { // mug is empty
            b = m;
        } else {
            int rem = g - a;
            int pour = min(rem, b);
            b -= pour;
            a += pour;
        }
    }

    printf("%d %d\n", a, b);
}

// ~ Jie ♥ Jenney