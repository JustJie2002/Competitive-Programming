/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.16.2023 22:47:47
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
    vector<vector<int>> groups(3);
    for (int i = 0; i < 13; i++) {
        auto s = nxt();
        int t = s[0] - '0' - 1;
        groups.push_back(s[1] - '0');
    }

    int n;
    for (int i = 0; i < n; i++) {
        i64 x;
        scanf("")
    }
}