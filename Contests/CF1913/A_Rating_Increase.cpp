/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 11:08:25
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

    if (s[0] == '0') {
        printf("-1\n");
        return;
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0') {
            continue;
        }
        int a = stoi(s.substr(0, i));
        int b = stoi(s.substr(i));
        if (a < b) {
            printf("%d %d\n", a, b);
            return;
        }
    }

    printf("-1\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}