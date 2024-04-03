/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 11:57:25
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

int main() {
    int n;
    scanf("%d", &n);
    auto s = fs.nxt();
    
    s += '$';
    vector<int> dif;
    int acc = 0;
    char p = s[0];
    for (auto c : s) {
        if (c != p && c != '.' && p != '.') {
            acc++;
        } else if (acc) {
            dif.push_back(acc);
        }
        p = c;
    }

    
}

// ~ Just Jie