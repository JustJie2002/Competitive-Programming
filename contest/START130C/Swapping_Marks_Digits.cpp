/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.17.2024 11:18:28
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

int get_max(string& s) {
    int res = stoi(s);
    reverse(s.begin(), s.end());
    res = max(res, stoi(s));
    return res;
}

int get_min(string& s) {
    int res = stoi(s);
    reverse(s.begin(), s.end());
    res = min(res, stoi(s));
    return res;
}

void work(int tc) {
    auto s = fs.nxt();
    auto t = fs.nxt();
    int a = get_max(s);
    int b = get_min(t);
    puts(a > b ? "Yes" : "No");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie