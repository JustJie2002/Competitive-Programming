/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 13:01:16
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

vector<string> check = {"keys", "phone", "wallet"};

int main() {
    int n;
    scanf("%d", &n);

    set<string> seen;
    for (int i = 0; i < n; i++) {
        auto s = fs.nxt();
        seen.insert(s);
    }

    sort(check.begin(), check.end());

    bool good = true;
    for (auto s : check) {
        if (!seen.contains(s)) {
            good = false;
            printf("%s\n", s.c_str());
        }
    }
    if (good) {
        puts("ready");
    }
}

// ~ Just Jie