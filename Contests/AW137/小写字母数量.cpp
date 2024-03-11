/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.08.2024 21:34:52
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 06062023
#endif

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
struct Reader {
    string nxt() {
        scanf("%s", buf);
        return buf;
    }
    char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
    string lst() {
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

int main() {
    auto s = fs.nxt();

    int ans = 0;
    for (char c : s) {
        if (islower(c)) {
            ans++;
        }
    }
    printf("%d\n", ans);
}

// ~ Just Jie