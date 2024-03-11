/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.13.2023 02:48:54
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
    int n;
    scanf("%d", &n);
    auto s = nxt();

    int o = count(s.begin(), s.end(), 'O'), l = n - o;
    int co = 0, cl = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'O') {
            co++;
        } else {
            cl++;
        }
        if (2 * co != o && 2 * cl != l) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    puts("-1");
}

// ~ Jie ♥ Jenney