/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.26.2024 09:08:42
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

void workout(int tc) {
    int Q;
    scanf("%d", &Q);

    vector<string> stk;
    for (; Q--; ) {
        auto op = fs.nxt();

        if (op == "push") {
            auto e = fs.nxt();
            stk.push_back(e);
        } else if (op == "query") {
            if (stk.empty()) {
                puts("Anguei!");
            } else {
                printf("%s\n", stk.back().c_str());
            }
        } else if (op == "pop") {
            if (stk.empty()) {
                puts("Empty");
            } else {
                stk.pop_back();
            }
        } else if (op == "size") {
            printf("%zu\n", stk.size());
        } else {
            assert(false);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie