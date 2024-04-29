/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 19:20:45
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

void work(int tc) {
    int n;
    scanf("%d", &n);

    set<string> S;
    for (int i = 0; i < n; i++) {
        auto s = fs.nxt();
        S.insert(s);
    }
    printf("%zu\n", S.size());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie