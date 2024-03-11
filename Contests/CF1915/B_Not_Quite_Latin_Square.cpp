/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.28.2023 13:29:41
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

string s[N];

void workout(int tc) {
    int row;
    for (int i = 0; i < N; i++) {
        s[i] = nxt();
        if (s[i].find('?') != string::npos) {
            row = i;
        }
    }

    for (char c : "ABC") {
        if (s[row].find(c) == string::npos) {
            printf("%c\n", c);
            return;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}