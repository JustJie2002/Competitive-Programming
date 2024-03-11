/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.30.2023 01:31:33
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

void write() {
    puts("INVALID");
}

int main() {
    auto s = nxt();
    int n = s.length();

    if (s.find("OO") != string::npos) {
        write();
        return 0;
    }
    if (s.back() == 'O') {
        write();
        return 0;
    }

    for (int k = 0; ; k++) {
        i64 n = 1LL << k;
        for (auto par : s) {
            if (par == 'E') {
                n = n << 1;
                if ((n & (n - 1)) == 0) {
                    printf("%d\n", n);
                    return 0;
                }
            } else {
                if ((n - 1) % 3 == 0) {
                    n = (n - 1) / 3;
                } else {
                    printf("%d\n", n);
                    return 0;
                }
                if (n % 2 == 0 || n <= 1) {
                    printf("%d\n", n);
                    return 0;
                }
            }
        }
    }
}

// ~ Jie ♥ Jenney