/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.21.2023 15:27:36
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

    auto gen_next = [&](const string& s) -> string {
        int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0';
        int op1;
        if (a % 2 == 0) {
            if (b % 2 == 0) {

            } else {

            }
        } else {
            if (b % 2 == 0) {

            } else {

            }
        }
    };

    string cur = "aaa";
    int m = 0;
    do {
        printf("%s\n", cur.c_str());
        m++;
        cur = gen_next(cur);
    } while (m < n);
}