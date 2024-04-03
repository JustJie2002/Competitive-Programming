/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 11:38:43
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

constexpr int N = 21;

int aa[N][N], bb[N][N];
int ans[N][N];

int main() {
    int h, w, n, m;
    scanf("%d%d%d%d", &h, &w, &n, &m);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &aa[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &bb[i][j]);
        }
    }

    reverse(bb, bb + n);
    for (int i = 0; i < n; i++) {
        reverse(bb[i], bb[i] + m);
    }

    for (int i = 0; i < h - n + 1; i++) {
        for (int j = 0; j < w - m + 1; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    ans[i][j] += bb[k][l] * aa[i + k][j + l];
                }
            }
            printf("%d%c", ans[i][j], " \n"[j == w - m]);
        }
    }
}

// ~ Just Jie