/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.19.2024 09:48:21
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

constexpr int N = 2e5 + 1;

int pre[N], sum[N];

void workout(int tc) {
    int n;
    scanf("%d", &n);
    printf("%d\n", pre[n]);
}

void Init() {
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i / 10] + (i % 10);
        pre[i] = pre[i - 1] + sum[i];
    }
}

int main() {
    Init();
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie