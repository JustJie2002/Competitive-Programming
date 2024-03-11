/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.26.2023 18:50:33
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
    auto s = nxt(), t = nxt();

    int res = n, pos = 0;
    for (int i = 0; i < m - n + 1; i++) {
        int dif = 0;
        for (int j = 0; j < n; j++) if (s[j] != t[i + j]) {
            dif++;
        }
        if (dif < res) {
            res = dif;
            pos = i;
        }
    }

    printf("%d\n", res);
    for (int i = 0; i < n; i++) if (s[i] != t[pos + i]) {
        printf("%d ", i + 1);
    }
}

// ~ Jie ♥ Jenney