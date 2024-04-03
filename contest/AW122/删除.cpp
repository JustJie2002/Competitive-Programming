/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.27.2023 02:26:22
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
    auto s = nxt();
    
    int n = s.length();

    auto ord = [&](char c) -> int {
        return c - '0';
    };
    
    for (int i = 0; i < n; i++) {
        int x = ord(s[i]);
        if (x % 8 == 0) {
            printf("YES\n");
            printf("%d\n", x);
            return 0;
        } 
        for (int j = i + 1; j < n; j++) {
            int y = x * 10 + ord(s[j]);
            if (y % 8 == 0) {
                printf("YES\n");
                printf("%d\n", y);
                return 0;
            }
            for (int k = j + 1; k < n; k++) {
                int z = y * 10 + ord(s[k]);
                if (z % 8 == 0) {
                    printf("YES\n");
                    printf("%d\n", z);
                    return 0;
                }
            }
        }
    }

    printf("NO\n");
}

// ~ Jie ♥ Jenney