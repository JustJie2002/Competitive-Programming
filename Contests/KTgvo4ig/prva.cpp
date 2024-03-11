/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 06:34:42
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

int main() {
    int R, C;
    scanf("%d%d", &R, &C);

    vector<string> str(R);
    for (int i = 0; i < R; i++) {
        str[i] = nxt();
    }

    string sans = "~";
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (str[r][c] == '#') {
                continue;
            }
            {
                if (c == 0 || str[r][c - 1] == '#') {
                    int dc = c;
                    string cur_word;
                    while (dc < C && str[r][dc] != '#') {
                        cur_word += str[r][dc];
                        dc++;
                    }
                    if (cur_word.size() > 1) {
                        sans = min(sans, cur_word);
                    }
                }
            }
            {
                if (r == 0 || str[r - 1][c] == '#') {
                    int dr = r;
                    string cur_word;
                    while (dr < R && str[dr][c] != '#') {
                        cur_word += str[dr][c];
                        dr++;
                    }
                    if (cur_word.size() > 1) {
                        sans = min(sans, cur_word);
                    }
                }
            }
        }
    }

    printf("%s\n", sans.c_str());
}