/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.02.2024 18:19:50
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
    int n;
    scanf("%d", &n);

    bool good = false;
    vector<string> bad;
    string pre;
    for (int i = 0; i < n; i++) {
        auto s = fs.nxt();
        if (s == "Present!") {
            pre = "";
        } else {
            if (!pre.empty()) {
                bad.push_back(pre);
            }
            pre = s;
            if (i == n - 1) {
                bad.push_back(s);
            }
        }
    }

    int m = bad.size();
    if (m == 0) {
        puts("No Absences");
    } else {
        for (const auto& s : bad) {
            printf("%s\n", s.c_str());
        }
    }
}

// ~ Just Jie