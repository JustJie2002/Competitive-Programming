/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.29.2024 10:20:42
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
    static string lst() {
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

const vector<string> digits = {
    "***   * *** *** * * *** *** *** *** ***",
    "* *   *   *   * * * *   *     * * * * *",
    "* *   * *** *** *** *** ***   * *** ***",
    "* *   * *     *   *   * * *   * * *   *",
    "***   * *** ***   * *** ***   * *** ***"
};

/*
***   * * * *** *** *** ***
* *   * * *   *   *   * *  
* *   * *** *** *** *** ***
* *   *   * *     * *   * *
***   *   * *** *** *** ***

***   * *** *** * * *** *** *** *** ***
* *   *   *   * * * *   *     * * * * *
* *   * *** *** *** *** ***   * *** ***
* *   * *     *   *   * * *   * * *   *
***   * *** ***   * *** ***   * *** ***
*/

constexpr int N = 5;
const int M = digits[0].length();

string s[N];

int work(int piv) {
    int dig = 0;
    for (int i = 0; i < M; i += 4, dig++) {
        bool same = true;
        for (int k = 0; k < N && same; k++) {
            for (int j = 0; j < 3 && same; j++) {
                same &= (s[k][piv + j] == digits[k][i + j]);
            }
        }
        if (same) {
            return dig;
        }
    }

    return -1;
}

int main() {
    generate(s, s + N, fs.lst);

    int n = s[0].length();
    int val = 0;
    for (int i = 0; i < n; i += 4) {
        int d = work(i);
        if (d == -1) {
            val = -1;
            break;
        }
        val *= 10;
        val += d;
    }

    val %= 6;
    puts(val == 0 ? "BEER!!" : "BOOM!!");
}

// ~ Just Jie