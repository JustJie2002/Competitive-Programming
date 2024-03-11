/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.31.2023 12:56:10
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

    int lst = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        int d, r, g;
        scanf("%d%d%d", &d, &r, &g);
        t += d - lst;
        // check whether it's red light or green light
        int rem = t % (r + g);
        t += max(0, r - rem);
        lst = d;
    }
    t += m - lst;
    printf("%d\n", t);
}