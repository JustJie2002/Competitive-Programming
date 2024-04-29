/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 19:37:43
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

int main() {
    auto s = fs.nxt();
    auto t = fs.nxt();
    int n = s.length(), m = t.length();

    int i = 0;
    while (i < n && i < m && s[i] == t[i]) {
        i++;
    }

    int j = 0;
    while (n - j - 1 >= i && m - j - 1 >= i && s[n - j - 1] == t[m - j - 1]) {
        j++;
    }

    printf("%d\n", max(0, (m - j) - i));
}

// ~ Just Jie