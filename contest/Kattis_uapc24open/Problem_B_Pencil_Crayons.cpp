/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 13:04:30
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

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<string, int> occ;
        for (int j = 0; j < m; j++) {
            auto s = fs.nxt();
            occ[s]++;
        }
        for (const auto& [k, v] : occ) {
            ans += (v - 1);
        }
    }

    printf("%d\n", ans);
}

// ~ Just Jie