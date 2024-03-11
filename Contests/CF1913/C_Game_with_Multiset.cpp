/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 11:15:22
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define write   puts

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

constexpr int LOG = 32;

int w[LOG];

int main() {
    int Q;
    scanf("%d", &Q);

    int mx = -1;
    while (Q--) {
        int op, x;
        scanf("%d%d", &op, &x);

        if (op == 1) {
            w[x]++;
        } else if (op == 2) {
            for (int b = 30; b >= 0; b--) {
                int v = min(x >> b, w[b]);
                x -= v << b;
            }
            write(x == 0 ? "YES" : "NO");
        } else assert(0);
    }
}