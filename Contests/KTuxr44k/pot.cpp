/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.21.2023 14:52:56
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

int main() {
    int n;
    scanf("%d", &n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int a = x / 10;
        int p = x % 10;
        int add = 1;
        while (p--) {
            add *= a;
        }
        res += add;
    }

    printf("%d\n", res);
}