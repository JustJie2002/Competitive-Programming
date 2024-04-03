/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.12.2024 21:05:49
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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n - 1; i++) {
        int sub = a[i - 1];
        a[i - 1] -= sub;
        a[i] -= 2 * sub;
        a[i + 1] -= sub;
        if (a[i] < 0) {
            puts("NO");
            return;
        }
    }

    if (any_of(a.begin(), a.end(), [&](int x) { return x != 0; })) {
        puts("NO");
    } else {
        puts("YES");
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