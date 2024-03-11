/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.07.2024 18:20:07
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 06062023
#endif

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
struct Reader {
    string nxt() {
        scanf("%s", buf);
        return buf;
    }
    char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
    string lst() {
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
using Pos = pair<int, int>;

#define x   first
#define y   second

int main() {
    int n, Q;
    scanf("%d%d", &n, &Q);

    vector<Pos> pos;
    for (int i = n; i; i--) {
        pos.emplace_back(i, 0);
    }

    for (int q = 0; q < Q; q++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            char c = fs.cxt();
            auto cur = pos.back();
            switch (c) {
            case 'R': {
                cur.x++;
                break;
            } case 'L': {
                cur.x--;
                break;
            } case 'U': {
                cur.y++;
                break;
            } case 'D': {
                cur.y--;
                break;
            }}
            pos.push_back(cur);
        } else if (op == 2) {
            int p;
            scanf("%d", &p);
            int m = pos.size();
            auto now = pos[m - p];
            printf("%d %d\n", now.x, now.y);
        } else assert(false);
    }
}

// ~ Just Jie