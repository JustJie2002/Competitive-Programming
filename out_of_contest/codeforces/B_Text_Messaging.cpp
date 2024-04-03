/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.19.2023 23:54:58
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
struct Scanner {
    string nxt() {
        scanf("%s", buf);
        return buf;
    }
    string wnxt() {
        scanf("%c", buf); // if you used a scanf before then we have to read the spacebar or newline after that
        // scanf("%[^\n]", buf);
        fgets(buf, BUFSIZE, stdin);
        return buf;
    }
    char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
} sc;

using i64 = long long;
const string ending = ".!?";

int main() {
    int cutoff;
    scanf("%d", &cutoff);
    auto s = sc.wnxt();
    int n = s.size();

    vector<int> pos;
    pos.push_back(-2);
    for (int i = 0; i < n; i++) {
        if (ending.find(s[i]) != string::npos) {
            pos.push_back(i);
        }
    }

    int m = pos.size();
    int ans = 1, rem = cutoff;
    for (int i = 1; i < m; i++) {
        int from = pos[i - 1] + 2, to = pos[i];
        int sz = to - from + 1;
        if (sz > cutoff) {
            puts("Impossible");
            return 0;
        }
        if (sz <= rem) {
            if (rem == cutoff) {
                rem -= sz;
            } else {
                if (sz == rem) {
                    ans++;
                    rem = cutoff - sz;
                } else {
                    rem -= (sz + 1);
                }
            }
        } else {
            rem = cutoff - sz;
            ans++;
        }
    }
    
    printf("%d\n", ans);
}

// ~ Jie ♥ Jenney