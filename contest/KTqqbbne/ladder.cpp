/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 20:39:01
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

double PI = acos(-1.0);

// sohcahtoa

int main() {
    int h, deg;
    scanf("%d%d", &h, &deg);

    // sin(deg) = h / x
    // x = h / sin(deg)
    int ans = ceil(1.0 * h / sin(deg * PI / 180));
    printf("%d\n", ans);
}