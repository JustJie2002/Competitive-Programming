/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.28.2024 20:30:45
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

int get(char c) {
    if (c == 'r') return 0;
    if (c == 'e') return 1;
    if (c == 'd') return 2;
    assert(false);
}

constexpr int N = 3;

using Info = array<int, 2>;

int main() {
    int n;
    scanf("%d", &n);
    auto s = fs.nxt();

    vector wrong(N, vector<vector<int>>(N));
    for (int i = 0; i < N * n; i++) {
        int r = i % N;
        int id = get(s[i]);
        if (r == id) {
            continue;
        }
        wrong[r][id].push_back(i + 1);
    }

    vector<Info> swaps;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            while (!wrong[i][j].empty() && !wrong[j][i].empty()) {
                int a = wrong[i][j].back();
                int b = wrong[j][i].back();
                swaps.push_back({a, b});
                wrong[i][j].pop_back();
                wrong[j][i].pop_back();
            }
        }
    }

    auto op = [&](int i, int j) {
        return 0 ^ 1 ^ 2 ^ i ^ j;
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (wrong[i][j].empty()) {
                continue;
            }
            assert(wrong[j][i].empty());
            int k = op(i, j);
            assert(!wrong[j][k].empty());
            assert(!wrong[k][i].empty());
            while (!wrong[i][j].empty() && !wrong[j][k].empty() && !wrong[k][i].empty()) {
                int a = wrong[i][j].back();
                int b = wrong[j][k].back();
                int c = wrong[k][i].back();
                swaps.push_back({b, c});
                swaps.push_back({b, a});
                wrong[i][j].pop_back();
                wrong[j][k].pop_back();
                wrong[k][i].pop_back();
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            assert(wrong[i][j].empty());
        }
    }

    printf("%zu\n", swaps.size());
    for (const auto& [a, b] : swaps) {
        printf("%d %d\n", a, b);
    }
}

// ~ Just Jie