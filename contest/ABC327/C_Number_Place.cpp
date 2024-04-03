/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.05.2023 07:18:24
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

const int N = 9;
int mat[N][N], row[N], col[N];

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int good_mask = 0;
    for (int i = 1; i <= N; i++) {
        good_mask |= (1 << i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            row[i] |= (1 << mat[i][j]);
            col[j] |= (1 << mat[i][j]);
        }
    }

    bool good = true;
    for (int i = 0; i < N; i++) {
        good &= (row[i] == good_mask);
        good &= (col[i] == good_mask);
    }

    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            int cur_mask = 0;
            for (int di = 0; di < 3; di++) {
                for (int dj = 0; dj < 3; dj++) {
                    cur_mask |= (1 << mat[i + di][j + dj]);
                }
            }
            good &= (cur_mask == good_mask);
        }
    }

    puts(good ? "Yes" : "No");
}

// ~ Jie ♥ Jenney