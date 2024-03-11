/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.22.2024 01:10:23
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
using Info = pair<int, int>;

#define f   first
#define s   second

constexpr int LIM = int(5e5) + 5;

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    s--;

    vector<Info> loc(n);
    int tar = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &loc[i].f, &loc[i].s);
        tar += loc[i].f;
    }

    int pw = 1, cur = s, t = 0;
    int rep = LIM;
    for (int rep = 0; rep < LIM && 0 <= cur && cur < n && t != tar; rep++) {
        dbg(cur);
        if (loc[cur].f == 0) {
            int par = (pw < 0 ? -1 : +1);
            pw = par * pw;
            pw += loc[cur].s;
            par *= -1;
            pw *= par;
        } else if (loc[cur].f == 1) {
            if (abs(pw) >= loc[cur].s) {
                t++;
                loc[cur].f = -1;
            }
        }
        cur += pw;
    }

    printf("%d\n", t);
}

// ~ Just Jie