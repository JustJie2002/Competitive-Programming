/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 11:23:41
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
    auto t = fs.lxt();

    string s;
    for (auto c : t) {
        if (isalpha(c)) {
            s += tolower(c);
        }
    }

    int n = s.length();

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            puts("Palindrome");
            return 0;
        }
        if (i + 2 < n && s[i] == s[i + 2]) {
            puts("Palindrome");
            return 0;
        }
    }

    puts("Anti-palindrome");
}

// ~ Just Jie