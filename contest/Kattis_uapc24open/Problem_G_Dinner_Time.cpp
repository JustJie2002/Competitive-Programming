/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 14:27:01
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
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

int main() {
    int Q;
    scanf("%d", &Q);

    i64 ans = 1;
    i64 p = 0;
    i64 g = 0;
    for (int q = 0; q < Q; q++) {
        auto op = fs.cxt();
        i64 k;
        scanf("%lld", &k);

        if (op == 'P') {
            i64 pp = p;
            p += k;
            if (pp < g && g <= p) {
                ans++;
            }
        } else {
            i64 pg = g;
            g += k;
            i64 x = min(g, p);
            ans += max(0LL, x - pg);
        }
    }

    printf("%lld\n", ans);
}

// ~ Just Jie