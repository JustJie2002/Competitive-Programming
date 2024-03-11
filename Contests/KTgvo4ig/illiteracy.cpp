/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 06:15:11
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

using i64 = long long;

constexpr int N = 8;

/*
A: rotate neighbor
B: change x + 1 to x - 1
C: rotate 9 - x
D: 
*/

int main() {
    auto s = nxt();
    auto t = nxt();

    unordered_set<string> seen;
    queue<string> q;

    auto append = [&](string s) -> void {
        if (!seen.count(s)) {
            q.push(s);
            seen.insert(s);
        }
    };

    append(s);

    auto rot = [&](char c) -> char {
        if (c == 'F')
            return 'A';
        return c + 1;
    };

    for (int moves = 0; !q.empty(); moves++) {
        int Q = q.size();
        while (Q--) {
            auto cur = q.front();
            q.pop();

            if (cur == t) {
                printf("%d\n", moves);
                return 0;
            }

            for (int i = 0; i < N; i++) {
                auto nex = cur;
                char op = nex[i];
                int a, b, c, x, y;
                switch (op) {
                case 'A':
                    a = i - 1, b = i + 1;
                    if (a >= 0) {
                        nex[a] = rot(nex[a]);
                    }
                    if (b < N) {
                        nex[b] = rot(nex[b]);
                    }
                    break;
                case 'B':
                    a = i - 1, b = i + 1;
                    if (b < N) {
                        nex[b] = nex[a];
                    }
                    break;
                case 'C':
                    c = 9 - (i + 1) - 1;
                    assert(0 <= c && c < N);
                    nex[c] = rot(nex[c]);
                    break;
                case 'D':
                    if (i <= 3) {
                        for (int j = 0; j < i; j++) {
                            nex[j] = rot(nex[j]);
                        }
                    } else {
                        for (int j = i + 1; j < N; j++) {
                            nex[j] = rot(nex[j]);
                        }
                    }
                    break;
                case 'E':
                    if (i != 0 && i != N - 1) {
                        y = min(i, N - i - 2);
                        nex[i - y] = rot(nex[i - y]);
                        nex[i + y] = rot(nex[i + y]);
                    }
                    break;
                case 'F':
                    x = i + 1;
                    if (x & 1) {
                        y = (x + 9) / 2 - 1;
                        nex[y] = rot(nex[y]);
                    } else {
                        y = x / 2 - 1;
                        nex[y] = rot(nex[y]);
                    }
                }
                append(nex);
            }
        }
    }

    assert(0);
}