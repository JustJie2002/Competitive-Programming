/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 19:07:01
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

constexpr int A = 26;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> marked(A, -1);

    auto ord = [&](char c) -> int {
        return c - 'A';
    };

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        auto bb = fs.cxt();
        b[i] = int(bb == 'T');
    }

    getchar();
    auto l = fs.lxt();

    stack<int> stk;
    int id = 0;
    for (char c : l) {
        if (isspace(c)) {
            continue;
        }
        if (isalpha(c)) {
            int o = ord(c);
            if (marked[o] == -1) {
                marked[o] = b[id++];
            }
            stk.push(marked[o]);
        } else {
            int x, y;
            switch (c) {
            case '*':
                assert(stk.size() >= 2);
                x = stk.top(); stk.pop();
                y = stk.top(); stk.pop();
                stk.push(x & y);
                break;
            case '+':
                assert(stk.size() >= 2);
                x = stk.top(); stk.pop();
                y = stk.top(); stk.pop();
                stk.push(x | y);
                break;
            case '-':
                assert(stk.size() >= 1);
                x = stk.top(); stk.pop();
                stk.push(!x);
                break;
            default:
                assert(false);
            }
        }
    }

    assert(stk.size() == 1);
    puts(stk.top() ? "T" : "F");
}

// ~ Just Jie