/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.05.2023 07:11:41
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

int main() {
    int n;
    scanf("%d", &n);
    auto s = nxt();

    puts(s.find("ab") != string::npos || s.find("ba") != string::npos ? "Yes" : "No");
}

// ~ Jie ♥ Jenney