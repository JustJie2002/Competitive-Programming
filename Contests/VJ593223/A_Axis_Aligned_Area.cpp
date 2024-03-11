/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.08.2023 13:25:43
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

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

using i64 = long long;

const int N = 4, inf = 1e9 + 5;
int s[N];

int main() {
    for (int i = 0; i < N; i++) {
        scanf("%d", &s[i]);
    }

    sort(s, s + N);

    int ans = 0;
    do {
        int a = min(s[0], s[1]);
        int b = min(s[2], s[3]);
        ans = max(ans, a * b);
    } while (next_permutation(s, s + N));

    printf("%d\n", ans);
}

// ~ Jie ♥ Jenney