/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.15.2024 10:36:25
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

    if (n & 1) {
        puts("NO");
    } else {
        // we can have a substring length >= 2 and it will have 2 special characters
        string s;
        for (int i = 0; i < n / 2; i++) {
            if (i & 1) {
                s += "AA";
            } else {
                s += "BB";
            }
        }
        puts("YES");
        printf("%s\n", s.c_str());
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie