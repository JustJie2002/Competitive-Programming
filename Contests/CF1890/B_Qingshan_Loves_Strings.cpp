/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.28.2023 10:41:25
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
    int n, m;
    scanf("%d%d", &n, &m);
    auto s = nxt(), t = nxt();

    bool good = true;
    for (int i = 0; i < m - 1; i++) {
        good &= (t[i] != t[i + 1]);
    }

    bool good2 = true;
    for (int i = 0; i < n - 1; i++) {
        good2 &= (s[i] != s[i + 1]);
    }

    if (good2) {
        puts("Yes");
        return;
    }

    if (!good) {
        puts("No");
        return;
    }

    if (t[0] != t.back()) {
        puts("No");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == t[0]) {
            puts("No");
            return;
        }
    }
    puts("Yes");

    // vector<bool> L(n), R(n);
    // L[0] = true;
    // for (int i = 1; i < n; i++) {
    //     L[i] = (L[i - 1] && s[i] != s[i - 1]);
    // }
    // R[n - 1] = true;
    // for (int i = n - 2; i >= 0; i--) {
    //     R[i] = (R[i + 1] && s[i] != s[i + 1]);
    // }

    // if (R[0] && s[0] != t.back()) {
    //     puts("Yes");
    //     return;
    // }
    // if (L[n - 1] && s.back() != t[0]) {
    //     puts("Yes");
    //     return;
    // }

    // for (int i = 0; i < n - 1; i++) {
    //     if (L[i] && R[i + 1] && s[i] != t[0] && s[i + 1] != t.back()) {
    //         puts("Yes");
    //         return;
    //     }
    // }

    // puts("No");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney