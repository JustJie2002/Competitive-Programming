/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 19:16:23
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
    int n, m;
    scanf("%d%d", &n, &m);

    vector<string> board(n);
    generate(board.begin(), board.end(), fs.nxt);

    vector vis(n, vector<bool>(m));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || board[i][j] != '#') {
                continue;
            }
            dbg(i, j);
            bool looping = false;
            y_combinator([&](auto&& dfs, int ci, int cj, int pi, int pj) -> void {
                vis[ci][cj] = true;
                auto good = [&](int i, int j) -> bool {
                    bool ok = (0 <= i && i < n);
                    ok &= (0 <= j && j < m);
                    ok = ok && (board[i][j] == '#');
                    ok &= (i != pi || j != pj);
                    return ok;
                };

                for (int di = -1; di < 2; di++) {
                    for (int dj = -1; dj < 2; dj++) {
                        if (di || dj) {
                            int ni = ci + di;
                            int nj = cj + dj;
                            if (good(ni, nj)) {
                                if (vis[ni][nj]) {
                                    looping = true;
                                } else {
                                    dfs(ni, nj, ci, cj);
                                }
                            }
                        }
                    }
                }
            })(i, j, i, j);
            ans += int(looping);
        }
    }

    printf("%d\n", ans);
}

// ~ Just Jie