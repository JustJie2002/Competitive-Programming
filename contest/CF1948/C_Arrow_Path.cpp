/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.15.2024 10:49:57
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

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

constexpr int dir[] = {0, 1, 0, -1, 0};

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<string> board(2);
    generate(board.begin(), board.end(), fs.nxt);

    auto encode = [&](int i, int j) -> int {
        return i * n + j;
    };

    vector vis(2, vector<bool>(n));

    y_combinator([&](auto&& dfs, int i, int j) -> void {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k + 1];
            if (0 <= ni && ni < 2 && 0 <= nj && nj < n) {
                if (board[ni][nj] == '<') {
                    nj = max(0, nj - 1);
                } else {
                    nj = min(n - 1, nj + 1);
                }
                if (!vis[ni][nj]) {
                    dfs(ni, nj);
                }
            }
        }
    })(0, 0);

    puts(vis[1][n - 1] ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie