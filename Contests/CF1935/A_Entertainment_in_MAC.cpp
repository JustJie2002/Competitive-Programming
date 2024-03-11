/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.05.2024 09:36:20
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
    auto s = fs.nxt();
    auto t = s;
    reverse(t.begin(), t.end());

    if (n == 1) {
        auto res = min(s, t);
        printf("%s\n", res.c_str());
    } else if (n % 2 == 0) {
        auto res = min({s, t + s});
        printf("%s\n", res.c_str());
    } else {
        auto res = min({t, t + s, s + t});
        printf("%s\n", res.c_str());
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