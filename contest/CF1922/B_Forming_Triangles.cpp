/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.18.2024 13:15:46
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

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }

    i64 pre = 0;
    i64 ans = 0;
    
    auto choose3 = [&](int x) -> i64 {
        if (x < 3) {
            return 0;
        }
        i64 res = 1LL * x * (x - 1) * (x - 2);
        res /= 6;
        return res;
    };

    auto choose2 = [&](int x) -> i64 {
        if (x < 2) {
            return 0;
        }
        return 1LL * x * (x - 1) / 2;
    };

    for (const auto& [_, f] : freq) {
        ans += choose3(f);
        ans += choose2(f) * pre;
        pre += f;
    }

    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie