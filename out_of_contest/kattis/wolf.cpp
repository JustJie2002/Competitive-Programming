/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 10:33:34
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

constexpr int N = 52;

int main() {
    int Q;
    scanf("%d", &Q);

    if (N - Q > Q) {
        puts("impossible");
        return 0;
    } else if (N - Q < Q) {
        puts("possible");
        return 0;
    }

    map<char, vector<int>> pos;
    while (Q--) {
        int x;
        scanf("%d", &x);
        auto suite = fs.cxt();
        pos[suite].push_back(x);
    }

    for (auto& [k, v] : pos) {
        sort(v.begin(), v.end());
        int mex = 1;
        for (int x : v) {
            if (x == mex) {
                mex++;
            } else {
                puts("possible");
                return 0;
            }
        }
    }
    puts("impossible");
}

// ~ Just Jie