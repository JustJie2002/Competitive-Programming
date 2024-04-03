/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.05.2023 11:44:26
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

    array<int, 26> freq {};
    for (char c : s) {
        int o = ord(c);
        freq[o]++;
    }

    int ma = 0;
    for (int i = 0; i < 26; i++) if (freq[i]) {
        ma = max(ma, freq[i]);
    }

    if (ma >= (n + 1) / 2) {
        int rem = n - ma;
        printf("%d\n", ma - rem);
    } else {
        puts(n % 2 == 0 ? "0" : "1");
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