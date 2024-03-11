/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.04.2023 03:12:30
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
    int n;
    scanf("%d", &n);

    array<int, 2> par {};
    set<i64> s;
    for (int i = 0; i < n; i++) {
        i64 x;
        scanf("%lld", &x);
        par[x % 2]++;
        s.insert(x);
    }

    puts(par[0] <= 1 && s.size() == n ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney