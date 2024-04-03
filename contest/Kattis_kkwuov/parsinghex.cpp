/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 17:47:43
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

void work(const string& l) {
    int n = l.size();

    vector<int> pos;
    for (int i = 0; i < n - 2; i++) {
        auto s = l.substr(i, 2);
        if (s == "0x" || s == "0X") {
            pos.push_back(i + 2);
        }
    }

    auto good = [&](char c) -> int {
        if (isdigit(c)) {
            return c - '0';
        }
        if (!isalpha(c)) {
            return -1;
        }
        c = tolower(c);
        return (c <= 'f' ? c - 'a' + 10 : -1);
    };

    for (auto spos : pos) {
        string hex = l.substr(spos - 2, 2);
        i64 dec = 0;
        for (int i = 0; i < 8; i++) {
            if (spos + i == n) {
                break;
            }
            auto x = good(l[spos + i]);
            if (x == -1) {
                break;
            }
            dec *= 16LL;
            dec += x;
            hex += l[spos + i];
        }
        if (hex == "0x") {
            continue;
        }
        printf("%s %lld\n", hex.c_str(), dec);
    }
}

int main() {
    while (true) {
        auto l = fs.lxt();
        if (l.empty()) {
            break;
        }
        work(l);
    }
}

// ~ Just Jie