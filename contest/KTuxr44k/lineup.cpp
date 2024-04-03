/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.21.2023 14:45:44
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

    vector<string> s(n);
    generate(s.begin(), s.end(), nxt);

    auto t = s;
    sort(t.begin(), t.end());

    if (s == t) {
        puts("INCREASING");
    } else {
        reverse(t.begin(), t.end());
        puts(s == t ? "DECREASING" : "NEITHER");
    }
}