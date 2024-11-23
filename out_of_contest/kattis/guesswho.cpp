/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.02.2024 18:11:01
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

const char ANY = '?';

int main() {
    int n, m, Q;
    scanf("%d%d%d", &n, &m, &Q);
    vector<string> strs(n);
    generate(strs.begin(), strs.end(), fs.nxt);

    string ans(m, ANY);
    for (int q = 0; q < Q; q++) {
        int i;
        scanf("%d", &i);
        i--;
        auto c = fs.cxt();
        ans[i] = c;
    }

    vector<int> matches;
    for (int i = 0; i < n; i++) {
        bool good = true;
        for (int j = 0; j < m && good; j++) {
            good &= (ans[j] == ANY || ans[j] == strs[i][j]);
        }
        if (good) {
            matches.push_back(i + 1);
        }
    }

    int sz = matches.size();
    if (sz == 1) {
        puts("unique");
        printf("%d\n", matches[0]);
    } else {
        puts("ambiguous");
        printf("%d\n", sz);
    }
}

// ~ Just Jie