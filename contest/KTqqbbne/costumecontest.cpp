/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 20:42:16
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

    map<string, int> freq;
    for (int i = 0; i < n; i++) {
        auto s = nxt();
        freq[s]++;
    }

    map<int, vector<string>> p;
    for (auto& [s, cnt] : freq) {
        p[cnt].push_back(s);
    }

    for (const auto& s : p.begin()->second) {
        printf("%s\n", s.c_str());
    }
}