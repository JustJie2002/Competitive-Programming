/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2023 02:42:34
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

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int m = 0;
    for (int i = 0; i < n; i = (1 << m), m++) {
        int j = min(n, 1 << m);
        // has to be non-decreasing
        bool non_decreasing = true;
        for (int k = i + 1; k < j; k++) {
            non_decreasing = non_decreasing && (a[k] >= a[k - 1]);
        }
        if (!non_decreasing) {
            puts("NO");
            return;
        }
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

// ~ Jie ♥ Jenney