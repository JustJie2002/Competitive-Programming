/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.16.2023 21:00:39
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

constexpr int a[] = {5, 5, 5, 5, 5, 5, 5, 5, 6, 5, 5, 6};

int main() {
    int n;
    scanf("%d", &n);
    n--;
    printf("%d\n", a[n]);
}