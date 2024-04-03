/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.08.2023 13:46:05
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

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

int foo(int x) {
    int res = 0;
    while (x) {
        res += (x % 10);
        x /= 10;
    }
    return res;
}

int main() {
    int d;
    scanf("%d", &d);

    string str;
    string ts = to_string(d);
    for (int _ = 0; _ < d; _++) {
        str += ts;
    }

    printf("%s\n", str.c_str());
}

// ~ Jie ♥ Jenney