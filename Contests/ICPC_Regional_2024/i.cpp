/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.30.2023 01:56:02
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

void write() {
    puts("invalid");
}

int ord(char c) {
    return c - '0';
}

void workout(int tc) {
    auto s = nxt();
    int n = s.length();

    if (n < 10) {
        return write();
    }
    if (count(s.begin(), s.end(), '-') > 3) {
        return write();
    }
    if (s[0] == '-' || s.back() == '-') {
        return write();
    }
    if (s.find("--") != string::npos) {
        return write();
    }

    int tot = 0, f = 10, d = 0;
    for (auto c : s) {
        if (isdigit(c) || c == 'X') {
            tot += (c == 'X' ? 10 : ord(c)) * f;
            tot %= 11;
            f--;
            d++;
        }
    }

    if (d != 10) {
        return write();
    }
    if (tot != 0) {
        return write();
    }
    s.pop_back();
    string sb = "978-" + s;

    if (count(s.begin(), s.end(), '-') == 3 && sb.back() != '-') {
        return write();
    }
    if (sb.find('X') != string::npos) {
        return write();
    }

    f = 1;
    for (auto c : sb) {
        if (isdigit(c)) {
            tot += ord(c) * f;
            tot %= 10;
            f ^= (1 ^ 3);
        }
    }

    int r = 10 - tot;
    if (r == 10) r = 0;

    sb += char(r + '0');
    printf("%s\n", sb.c_str());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney