/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.01.2023 00:52:55
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
    auto a = nxt(), s = nxt(), t = nxt();

    if (s.size() < t.size()) {
        swap(s, t);
    }

    auto compare = [&](const string& p, const string& s, const string& t) {
        string str = p + p;
        int tot = 0;
        int n = s.size(), m = t.size();
        for (int i = 0; i < p.size(); i++) {
            tot += (str.substr(i, n) == s ? 1 : 0);
            tot -= (str.substr(i, m) == t ? 1 : 0);
        }
        return tot > 0;
    };

    queue<string> Q;
    Q.push(s);
    int tries = 1000;
    while (!Q.empty() && tries--) {
        auto u = Q.front();
        Q.pop();
        if (compare(u, s, t)) {
            puts("0");
            return;
        }
        for (char x : a) {
            Q.push(u + x);
        }
    }

    puts("1");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney