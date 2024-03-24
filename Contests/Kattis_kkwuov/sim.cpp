/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 18:51:11
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
    auto l = fs.lxt();
    l += ']';

    deque<string> dq;
    bool back = true;
    string t;
    for (char c : l) {
        if (c == ']') {
            if (!t.empty()) {
                if (back) {
                    dq.push_back(t);
                } else {
                    dq.push_front(t);
                }
                t.clear();
            }
            back = true;
        } else if (c == '[') {
            if (!t.empty()) {
                if (back) {
                    dq.push_back(t);
                } else {
                    dq.push_front(t);
                }
                t.clear();
            }
            back = false;
        } else if (c == '<') {
            if (!t.empty()) {
                t.pop_back();
            } else if (back && !dq.empty()) {
                auto s = dq.back();
                dq.pop_back();
                s.pop_back();
                if (!s.empty()) {
                    dq.push_back(s);
                }
            }
        } else {
            t += c;
        }
    }

    string s;
    while (!dq.empty()) {
        s += dq.front();
        dq.pop_front();
    }

    printf("%s\n", s.c_str());
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie