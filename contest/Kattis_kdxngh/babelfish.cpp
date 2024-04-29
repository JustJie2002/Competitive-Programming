/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 19:14:50
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

map<string, string> dic;

void Init() {
    string s;
    while (true) {
        s = fs.lxt();
        if (s.empty()) return;
        int i = 0;
        while (!isspace(s[i])) i++;
        auto to = s.substr(0, i);
        auto from = s.substr(i + 1);
        dic[from] = to;
    }
}

void work() {
    string s;
    while (scanf("%s", buf) != EOF) {
        s = buf;
        if (dic.contains(s)) {
            printf("%s\n", dic[s].c_str());
        } else {
            puts("eh");
        }
    }
}

int main() {
    Init();
    work();
}

// ~ Just Jie