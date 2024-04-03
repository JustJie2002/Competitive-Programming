/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 18:18:42
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

    vector<int> div(3);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        div[x % 3]++;
    }

    int tot = (div[1] + div[2] * 2) % 3;
    dbg(tot);

    if (tot == 0) {
        puts("0");
    } else if (tot == 1) {
        // we can remove an e with remainder 1
        if (div[1]) {
            puts("1");
        } else {
            puts("2");
        }
    } else if (tot == 2) {
        puts("1");
    } else {
        assert(false);
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