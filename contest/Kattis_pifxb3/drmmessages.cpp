/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.16.2024 00:00:23
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

int main() {
    auto s = fs.nxt();
    int n = s.length();

    auto a = s.substr(0, n / 2);
    auto b = s.substr(n / 2);

    auto get = [&](char c, int o) {
        int ord = c - 'A';
        ord += o;
        ord %= 26;
        return char(ord + 'A');
    };
    auto rot = [&](auto& str) {
        int res = 0;
        for (auto c : str) {
            res += (c - 'A');
        }
        for (auto& c : str) {
            c = get(c, res);
        }
    };

    rot(a);
    rot(b);

    for (int i = 0; i < n / 2; i++) {
        a[i] = get(a[i], b[i] - 'A');
    }

    printf("%s\n", a.c_str());
}

// ~ Just Jie