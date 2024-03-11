/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.28.2023 13:28:42
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
    map<int, int> freq;
    for (int i = 0; i < 3; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }
    for (auto& [x, f] : freq) {
        if (f == 1) {
            printf("%d\n", x);
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