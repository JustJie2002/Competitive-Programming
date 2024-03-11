/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.16.2023 22:37:40
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

constexpr int N = 1001;

int aa[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &aa[i][j]);
        }
    }

    
}