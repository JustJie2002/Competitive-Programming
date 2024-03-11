/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.31.2023 13:02:49
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
string lst() {
    string sb;
    char c;
    while (c = getchar()) {
        if (c == '\n' || c == EOF) {
            break;
        }
        if (isspace(c)) {
            c = '$';
        }
        sb += c;
    }
    return sb;
}

using i64 = long long;

vector<int> z_func(const string& s) {
    int n = s.length();
    vector<int> z(n);
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        z[i] = (i >= r ? 0 : min(r - i, z[i - l]));
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    while (true) {
        auto s = lst();
        if (s.empty()) {
            break;
        }
        auto t = lst();
        int n = s.length(), m = t.length();
        s += '#';
        s += t;
        auto z = z_func(s);
        for (int i = n + 1; i < n + m + 1; i++) {
            if (z[i] == n) {
                printf("%d ", i - n - 1);
            }
        }
        printf("\n");
    }
}