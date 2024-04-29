/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.24.2024 20:09:05
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
    auto s = fs.nxt();

    auto get_answer = [&](int i) {
        int a = 0, b = 0;
        i64 ans = 0;
        int bef = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == 'a') {
                b += bef;
                bef = 0;
                if (b != 0) {
                    a++;
                }
            } else if (s[j] == 'b') {
                bef++;
            }
            ans += min(a, b);
        }
        return ans;
    };

    i64 ans = 0;
    i64 bef = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'c') {
            auto res = get_answer(i);
            ans += bef * res;
            bef = 1;
        } else {
            bef++;
        }
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie