/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2023 15:32:00
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
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);

    if (x < y) {
        int dis = y - x;
        if (dis <= k) {
            printf("%d\n", y);
        } else {
            printf("%d\n", y + y - (x + k));
        }
    } else {
        printf("%d\n", x);
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