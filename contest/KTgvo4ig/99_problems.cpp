/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 06:31:26
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

constexpr int inf = 1e9 + 5;

int main() {
    int n;
    scanf("%d", &n);

    array<int, 2> res = {inf, inf};
    for (int pre = 0; pre <= 101; pre++) {
        int cur = pre * 100 + 99;
        int dif = abs(cur - n);
        if (dif <= res[0]) {
            res[0] = dif;
            res[1] = cur;
        }
    }

    printf("%d\n", res[1]);
}