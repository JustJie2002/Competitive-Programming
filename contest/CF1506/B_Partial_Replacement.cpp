/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.31.2024 23:24:02
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
struct Reader {
    static string nxt() {
        scanf("%s", buf);
        return buf;
    }
    static char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
    static string lxt() {
        char c;
        string sb;
        while (c = getchar()) {
            if (c == '\n' || c == EOF) {
                break;
            }
            sb += c;
        }
        return sb;
    }
} fs;

using i64 = long long;

void workout(int tc) {
    int n, k;
    scanf("%d%d", &n, &k);
    auto s = fs.nxt();

    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            pos.push_back(i);
        }
    }

    int m = pos.size();

    if (m <= 2) {
        printf("%d\n", m);
    } else {
        int lst = pos[0];
        int ans = 2;
        for (int i = 0; i < m; i++) {
            if (pos[i] - lst > k) {
                ans++;
                lst = pos[i - 1];
            }
        }
        printf("%d\n", ans);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie