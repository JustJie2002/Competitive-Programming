/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.06.2024 11:56:43
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

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

struct Manacher {
    string word;
    vector<int> man;
    int pal_count;

    Manacher() {
        word += '#';
    }

    void add(const string& s) {
        for (char c : s) {
            word += c;
            word += '#';
        }
    }

    char _get(int pos) {
        return word[pos];
    }

    void work() {
        int n = word.length();
        man.resize(n);
        pal_count = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (2 * j - i >= 0 && j + man[j] > i) {
                man[i] = min(man[2 * j - i], j + man[j] - i);
            }
            while (i - man[i] >= 0 && i + man[i] < n && _get(i - man[i]) == _get(i + man[i])) {
                man[i] += 1;
            }
            if (i + man[i] > j + man[j]) {
                j = i;
            }
            pal_count += man[i] / 2;
        }
    }

    int count_pal() {
        return pal_count;
    }

    int get(int mid, bool odd) {
        return man[2 * mid + !odd + 1] - 1;
    }

    bool is_pal(int l, int r) {
        int sz = r - l + 1;
        int mid = (l + r) / 2;
        int len = get(mid, sz & 1);
        return sz <= len;
    }
};

void workout(int tc) {
    auto s = fs.nxt();
    int n = s.length();

    Manacher man;
    man.add(s);
    man.work();

    if (!man.is_pal(0, n - 1)) {
        puts("YES");
        puts("1");
        printf("%s\n", s.c_str());
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        if (!man.is_pal(0, i) && !man.is_pal(i + 1, n - 1)) {
            puts("YES");
            puts("2");
            printf("%s %s\n", s.substr(0, i + 1).c_str(), s.substr(i + 1).c_str());
            return;
        }
    }
    puts("NO");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie