/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.16.2024 00:08:13
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

bool work(auto& s) {
    int n = s.length();
    
    int pre = -1;
    int lst = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '*') {
            int d = i - lst - 1;
            if (pre == -1) {
                pre = d;
            } else if (pre != d) {
                return false;
            }
            lst = i;
        }
    }

    return true;
}

int main() {
    string s;
    for (int t = 1; (s = fs.nxt()) != "END"; t++) {
        printf("%d ", t);
        puts(work(s) ? "EVEN" : "NOT EVEN");
    }
}

// ~ Just Jie