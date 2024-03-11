/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 20:28:14
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

const string VOWELS = "aeiou";

int main() {
    auto s = fs.lxt();

    int ans = 0;
    for (auto c : s) {
        if (!isalpha(c)) {
            continue;
        }
        c = tolower(c);
        if (VOWELS.find(c) != string::npos) {
            ans++;
        }
    }

    printf("%d\n", ans);
}

// ~ Just Jie