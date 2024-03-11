/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.10.2024 20:20:11
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

constexpr int A = 26;
const char min_char = 'A';

constexpr int ord(char c) {
    return c - min_char;
}

int main() {
    auto s = fs.nxt();

    array<int, A> freq {};

    for (auto c : s) {
        freq[ord(c)]++;
    }

    vector<int> e, o;
    for (int a = 0; a < A; a++) {
        if (freq[a] & 1) {
            o.push_back(a);
        } else {
            e.push_back(a);
        }
    }

    if (o.size() > 1) {
        puts("NO SOLUTION");
        return 0;
    }

    string t;
    for (int a : e) {
        t += string(freq[a] / 2, a + min_char);
    }
    auto rev = t;
    reverse(rev.begin(), rev.end());
    for (int a : o) {
        c = char(a + min_char);
        center = true;
    }


    printf("%s\n", t.c_str());
}

// ~ Just Jie