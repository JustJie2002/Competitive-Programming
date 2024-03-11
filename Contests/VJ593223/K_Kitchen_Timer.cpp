/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.08.2023 13:30:33
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

const int MAX_BIT = 62;
i64 pw2[MAX_BIT + 1], pre[MAX_BIT + 1];

void Init() {
    pw2[0] = 1;
    pre[0] = 1;
    for (int i = 0; i < MAX_BIT; i++) {
        pw2[i + 1] = pw2[i] * 2;
        pre[i + 1] = pre[i] + pw2[i + 1];
    }
}

void workout(int tc) {
    i64 N;
    scanf("%lld", &N);

    int ans = 0;
    for (int i = MAX_BIT; i >= 0; i--) {
        ans += N / pre[i];
        N %= pre[i];
    }

    printf("%d\n", ans - 1);
}

int main() {
    Init();
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney