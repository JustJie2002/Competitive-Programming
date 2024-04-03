/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.03.2024 11:30:23
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
using Pos = array<int, 2>;

constexpr int N = 101, R = 4, C = 10, M = R * C + 1;
const string END = "*";
const int dr[] {-3, -3, -1, -1, 3, 3, 1, 1};
const int dc[] {-1, 1, 3, -3, 1, -1, 3, -3};
int pred[N][M][M];

struct State {
    array<Pos, 2> state;
    State() {}
    State move(int k, int d) {
        auto new_state = state;
        state[k][0] += dr[d]
        state[k][1] += dc[d];
        return state;
    }
};

const string board[] {
    "qwertyuiop",
    "asdfghjkl",
    "zxcvbnm,./",
};

char get(const Pos& pos, bool is_upper = false) {
    const auto& [r, c] = pos; 
    if (r == 0) {
        char chr = board[r][c];
        return is_upper ? toupper(chr) : chr;
    } else if (r == 1) {
        if (c == 9) {
            return is_upper ? ':' : ';';
        }
        char chr = board[r][c];
        return is_upper ? toupper(chr) : chr;
    } else if (r == 2) {
        if (c == 7) {
            return is_upper ? '<' : ',';
        } else if (c == 8) {
            return is_upper ? '>' : '.';
        } else if (c == 9) {
            return is_upper ? '?' : '/';
        }
        char chr = board[r][c];
        return is_upper ? toupper(chr) : chr;
    } else if (r == 3) {
        return (c < 2 || c > 7 ? '\t' : ' ');
    } else assert(false);
}

void workout(const string& s) {
    int n = s.length();

    memset(pred, -1, sizeof(pred)); // mark them all as unvisited

    queue<State> q;
    auto add = [&](const State& from, const State& to) {
        
    };

    for (int i = 0; i < n; i++) {
        int Q = q.size();
        while (Q--) {
            State cur = q.front();
            q.pop();

            auto good = [&](const Pos& pos) -> bool {
                return 0 <= pos[0] && pos[0] < R && 0 <= pos[1] && pos[1] < C;
            };
            auto make_sure = [&](State& state, int moved) {
                if (state[moved] == state[!moved]) {
                    return false;
                }
                if (!good(state[moved])) {
                    return false;
                }
                bool is_upper = get(state[!moved]) == '\t';
                char c = get(state[moved], is_upper);
                if (s[i] == c) {
                    if (state[0] > state[1]) {
                        swap(state[0], state[1]);
                    }
                    return true;
                }
                return false;
            };

            for (int d = 0; d < 8; d++) {
                State nxt1 = cur.move(0, d);
                if (make_sure(nxt1, 0)) {

                }
                State nxt2 = cur.move(1, d);
                if (make_sure(nxt2, 1)) {

                }
            }
        }
    }
}

int main() {
    string s;
    while ((s = fs.lxt()) != END) {
        workout(s);
    }
}

// ~ Just Jie