/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.27.2023 00:16:00
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

constexpr int N = 3;
int a[N];

void workout(int tc) {
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N; i++) {
        int tot = 0;
        int cur = a[i];
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (tot == 0) {
                    tot += a[j];
                } else {
                    tot = abs(tot - a[j]);
                }
            }
        }
        cur += tot;

        if (tot >= cur) {
            printf("0 ");
        } else {
            printf("1 ");
        }
    }
    puts("");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney