/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.16.2024 00:52:14
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
using Pair = pair<int, int>;

constexpr int N = 4;
Pair a[N];

void workout(int tc) {
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    
    sort(a, a + N);

    const auto& BL = a[0];
    const auto& TR = a[N - 1];
    int ans = (TR.first - BL.first) * (TR.second - BL.second);
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie