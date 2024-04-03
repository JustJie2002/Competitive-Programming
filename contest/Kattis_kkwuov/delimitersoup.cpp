/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 19:00:09
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

const string BRAC = "([{)]}";

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    auto l = fs.lxt();

    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (isspace(l[i])) {
            continue;
        }
        int idx = find(BRAC.begin(), BRAC.end(), l[i]) - BRAC.begin();
        if (idx < 3) { // it's an opening
            stk.push(idx);
        } else {
            if (stk.empty() || stk.top() != idx - 3) {
                printf("%c %d\n", l[i], i);
                return 0;
            }
            stk.pop();
        }
    }

    puts("ok so far");
}

// ~ Just Jie