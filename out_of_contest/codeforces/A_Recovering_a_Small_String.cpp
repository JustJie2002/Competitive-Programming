/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 02:43:39
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    auto chr = [&](int o) -> char {
        return (char) o + 'a';
    };

    string ans = "zzz";
    for (int a = 0; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
            for (int c = 0; c < 26; c++) {
                if (a + b + c + 3 == n) {
                    string res = "";
                    res += chr(a);
                    res += chr(b);
                    res += chr(c);
                    ans = min(ans, res);
                }
            }
        }
    }

    printf("%s\n", ans.c_str());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie