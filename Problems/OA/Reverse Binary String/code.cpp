/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.04.2024 19:45:43
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

int solve(string s) {
    int n = s.length();

    auto rev = s;
    reverse(rev.begin(), rev.end());
    
    int lp = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == rev[lp]) {
            lp++;
        }
    }

    return n - lp;
}

int main() {
    cout << solve("00110101") << "\n";
}

// ~ Just Jie