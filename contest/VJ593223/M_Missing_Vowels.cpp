/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.08.2023 14:05:26
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

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

using i64 = long long;

const string vowels = "aeiouy";

bool is_vowel(char c) {
    return vowels.find(c) != string::npos;
}

string all_lower(const string& str) {
    string s;
    for (char c : str) {
        s += tolower(c);
    }
    return s;
}

int main() {
    auto s = all_lower(nxt()), t = all_lower(nxt());

    int n = s.size(), m = t.size();

    string t_out;
    for (int i = 0, j = 0; i < m; i++) {
        if (j == n) {
            if (!is_vowel(t[i])) {
                t_out += t[i];
            }
        } else if (is_vowel(t[i]) && s[j] != t[i]) {
        } else {
            t_out += t[i];
            j++;
        }
    }

    puts(t_out == s ? "Same" : "Different");
}

// ~ Jie ♥ Jenney