/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.25.2024 17:43:42
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

struct Expression {
    string a, op, b, c;
    Expression() {}
    Expression(string _a, string _op, string _b, string _c) : a(_a), op(_op), b(_b), c(_c) {}
    void read() {
        a = fs.nxt();
        op = fs.nxt();
        b = fs.nxt();
        fs.nxt();
        c = fs.nxt();
    }

    void work() {
        i64 x = stoll(a);
        i64 y = stoll(b);
        i64 z = stoll(c);
        dbg(x, y, z);
        if (op == "+") {
            if (x + y == z) {
                out();
            }
        } else {
            if (x * y == z) {
                out();
            }
        }
    }

    void out() {
        printf("%s %s %s = %s\n", a.c_str(), op.c_str(), b.c_str(), c.c_str());
        exit(0);
    }
};

int main() {
    Expression e;
    e.read();
    auto a = e.a;
    auto op = e.op;
    auto b = e.b;
    auto c = e.c;

    { // swap prefix of a and b
        int n = a.size(), m = b.size();
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                auto new_a = b.substr(0, j) + a.substr(i);
                auto new_b = a.substr(0, i) + b.substr(j);
                Expression o(new_a, op, new_b, c);
                o.work();
            }
        }
    }
    { // swap prefix of a and c
        int n = a.size(), m = c.size();
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                auto new_a = c.substr(0, j) + a.substr(i);
                auto new_c = a.substr(0, i) + c.substr(j);
                Expression o(new_a, op, b, new_c);
                o.work();
            }
        }
    }
    { // swap prefix of b and c
        int n = b.size(), m = c.size();
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                auto new_b = c.substr(0, j) + b.substr(i);
                auto new_c = b.substr(0, i) + c.substr(j);
                Expression o(a, op, new_b, new_c);
                o.work();
            }
        }
    }
}

// ~ Just Jie