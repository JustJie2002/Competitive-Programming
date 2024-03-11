/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.18.2023 12:14:04
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
    auto s = nxt();
    auto p = s;
    sort(p.rbegin(), p.rend());
    if (p == s) {
        puts("no answer");
        return;
    }
    next_permutation(s.begin(), s.end());
    printf("%s\n", s.c_str());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}