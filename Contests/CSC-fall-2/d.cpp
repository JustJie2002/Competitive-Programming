/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.18.2023 12:36:12
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
    auto s = nxt();
    
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    map<int, int> freq2;
    for (auto &[_, f] : freq) {
        freq2[f]++;
    }

    int n = freq2.size();

    if (n == 1) {
        puts("YES");
        return 0;
    }
    if (n > 2) {
        puts("NO");
        return 0;
    }

    auto a = *freq2.begin();
    auto b = *freq2.rbegin();

    if (b.second == 1 && b.first - 1 == a.first) {
        puts("YES");
        return 0;
    }
    if (a.first == 1 && a.second == 1) {
        puts("YES");
        return 0;
    }

    puts("NO");
}