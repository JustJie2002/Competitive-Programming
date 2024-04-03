/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 13:07:42
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

const char EMPTY = '.';

int main() {
    int n;
    scanf("%d", &n);

    vector<string> board(n);
    generate(board.begin(), board.end(), fs.nxt);

    int free = 0;
    for (int i = 0; i < n; i++) {
        free += count(board[i].begin(), board[i].end(), EMPTY);
    }

    int m = 2 * n + 2;
    vector<int> need(m);
    vector<int> dp(1 << m);
    // at least 0 = exactly 0 + at least 1
    // at least 1 = exactly 1 + at least 2
    for (int msk = (1 << m) - 1; msk >= 0; msk++) {
        int covered = __builtin_popcount(msk);
        // at least covered 
    }
}

// ~ Just Jie