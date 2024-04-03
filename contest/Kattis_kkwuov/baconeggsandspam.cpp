/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 17:37:57
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

vector<string> sfunc(string s) {
    s += ' ';
    vector<string> res;
    string t;
    for (char c : s) {
        if (isspace(c)) {
            res.push_back(t);
            t.clear();
        } else {
            t += c;
        }
    }
    return res;
}

void work(int n) {
    getchar();

    map<string, vector<string>> eat;
    while (n--) {
        auto l = fs.lxt();
        auto words = sfunc(l);
        auto person = words[0];
        int m = words.size();
        for (int i = 1; i < m; i++) {
            eat[words[i]].push_back(person);
        }
    }

    for (auto& [food, peeps] : eat) {
        printf("%s ", food.c_str());
        sort(peeps.begin(), peeps.end());
        for (const auto& peep : peeps) {
            printf("%s ", peep.c_str());
        }
        puts("");
    }
    puts("");
}

int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        work(n);
    }
}

// ~ Just Jie