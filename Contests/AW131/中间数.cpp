/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.25.2023 18:07:26
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

int main() {
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + N);

    printf("%d\n", a[1]);
}

// ~ Jie ♥ Jenney