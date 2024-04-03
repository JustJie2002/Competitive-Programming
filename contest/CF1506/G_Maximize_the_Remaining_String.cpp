/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.01.2024 00:24:22
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

constexpr int A = 26;

set<int> pos[A];

void Init() {
    for (int a = 0; a < A; a++) {
        pos[a].clear();
    }
}

void workout(int tc) {
    auto s = fs.nxt();
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int o = s[i] - 'a';
        pos[o].insert(i);
    }

    vector<int> marked(n);
    set<int, greater<int>> put;
    int m = 0;
    for (int a = A - 1; a >= 0; a--) {
        int f = pos[a].size();
        if (f == 0) {
            continue;
        }
        if (f > 1) {
            if (m == 0) {
                put.insert(*pos[a].begin());
            } else {
                // I want to put behind everything
                set<int>::iterator it;
                for (int x : put) {
                    it = pos[a].lower_bound(x);
                    if (it != pos[a].end()) {
                        break;
                    }
                }
                if (it == pos[a].end()) {
                    it = pos[a].begin();
                }
                int i = *it;
                put.insert(i);
                marked[i] = 1;
            }
        } else if (f == 1) {
            int i = *pos[a].begin();
            put.insert(i);
            marked[i] = 1;
        }
        m++;
    }

    string t;
    for (int i = 0; i < n; i++) {
        if (marked[i]) {
            t += s[i];
        }
    }

    printf("%s\n", t.c_str());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        Init();
        workout(t);
    }
}

// ~ Just Jie