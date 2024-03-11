/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.05.2023 11:37:15
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
    auto cur = nxt();
    for (char c = '1'; c <= '8'; c++)
        if (c != cur[1]) {
            printf("%c%c\n", cur[0], c);
        }
    for (char c = 'a'; c <= 'h'; c++)
        if (c != cur[0]) {
            printf("%c%c\n", c, cur[1]);
        }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney