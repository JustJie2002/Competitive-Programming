/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.19.2024 09:42:04
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
    int n;
    scanf("%d", &n);

    vector<string> s(n);
    generate(s.begin(), s.end(), fs.nxt);

    int row = n, l = n, r = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                row = min(row, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }

    int sz = r - l;
    if (row + sz >= n) {
        puts("TRIANGLE");
    } else {
        if (s[row][l] == '1' && s[row][r] == '1' && s[row + sz][l] == '1' && s[row + sz][r] == '1') {
            puts("SQUARE");
        } else {
            puts("TRIANGLE");
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

// ~ Just Jie