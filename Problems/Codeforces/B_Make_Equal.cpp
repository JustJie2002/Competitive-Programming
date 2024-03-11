/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 02:49:38
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

constexpr int INF = int(1e9) + 5;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    int even = sum / n;

    int extra = 0;
    for (int x : a) {
        x += extra;
        extra = 0;
        if (x < even) {
            puts("NO");
            return;
        }
        extra = x - even;
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