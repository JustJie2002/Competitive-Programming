/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.12.2024 21:18:23
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

void workout(int tc) {
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);

    unordered_set<int> s;
    s.insert(x - 1);
    for (int q = 0; q < m; q++) {
        unordered_set<int> ns;
        int d;
        scanf("%d", &d);
        auto c = fs.cxt();
        for (int v : s) {
            if (c == '0' || c == '?') {
                ns.insert((v + d) % n);
            }
            if (c == '1' || c == '?') {
                ns.insert((v - d + n) % n);
            }
        }
        s = ns;
    }

    vector<int> a(s.begin(), s.end());
    sort(a.begin(), a.end());

    printf("%zu\n", a.size());
    for (int x : a) {
        printf("%d ", x + 1);
    }
    puts("");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie