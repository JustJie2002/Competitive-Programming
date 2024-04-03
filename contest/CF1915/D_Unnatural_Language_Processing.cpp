/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.28.2023 14:27:09
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
string nxt() {
    scanf("%s", buf);
    return buf;
}
char cxt() {
    scanf("%s", buf);
    return buf[0];
}

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

using i64 = long long;

bool is_vowel(char c) {
    return c == 'a' || c == 'e';
}

void workout(int tc) {
    int n;
    scanf("%d", &n);
    auto s = nxt();

    vector<string> res;
    int pre = 0;
    for (int i = 0; i < n - 1; i++) {
        if (!is_vowel(s[i]) && !is_vowel(s[i + 1])) {
            res.push_back(s.substr(pre, i - pre + 1));
            pre = i + 1;
        }
    }
    res.push_back(s.substr(pre));

    vector<string> strs;
    for (const auto& str : res) {
        int m = str.size();
        pre = 0;
        for (int i = 0; i < m - 2; i++) {
            if (is_vowel(str[i]) && !is_vowel(str[i + 1])) {
                strs.push_back(str.substr(pre, i - pre + 1));
                pre = i + 1;
            }
        }
        strs.push_back(str.substr(pre));
    }

    int m = strs.size();
    for (int i = 0; i < m; i++) {
        printf("%s%c", strs[i].c_str(), ".\n"[i == m - 1]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}