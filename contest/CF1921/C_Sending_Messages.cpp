/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.16.2024 00:59:07
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
    i64 f, a, b;
    scanf("%d%lld%lld%lld", &n, &f, &a, &b);

    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }

    m.push_back(0);
    sort(m.begin(), m.end());
    n++;

    for (int i = 1; i < n; i++) {
        int t = min(1LL * (m[i] - m[i - 1]) * a, b);
        if (f - t <= 0) {
            puts("NO");
            return;
        }
        f -= t;
    }
    puts("YES");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie