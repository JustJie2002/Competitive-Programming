/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 16:45:11
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
    auto s = fs.lxt();

    string t;
    for (auto c : s) {
        if (!isalpha(c)) {
            continue;
        }
        t += tolower(c);
    }

    int n = t.size();

    for (int i = 0; i < n - 1; i++) {
        if (t[i] == t[i + 1]) {
            puts("Palindrome");
            return 0;
        }
        if (i + 2 < n && t[i] == t[i + 2]) {
            puts("Palindrome");
            return 0;
        }
    }

    puts("Anti-palindrome");
}

// ~ Just Jie