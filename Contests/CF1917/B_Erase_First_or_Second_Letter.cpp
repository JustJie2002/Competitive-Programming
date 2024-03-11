/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.26.2023 21:00:20
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

constexpr int ord(char c) {
    return c - 'a';
}

void workout(int tc) {
    int n;
    scanf("%d", &n);
    auto s = nxt();

    int mask = 0, res = 0;
    for (char c : s) {
        mask |= (1 << ord(c))
        int ans = 0;
    }

    printf("%d\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}