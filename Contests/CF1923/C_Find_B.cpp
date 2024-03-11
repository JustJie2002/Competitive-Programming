/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.24.2024 03:22:59
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
using Info = pair<i64, int>;

Info operator-(const Info& a, const Info& b) {
    return {a.first - b.first, a.second - b.second};
}

void workout(int tc) {
    int n, Q;
    scanf("%d%d", &n, &Q);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<Info> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        pre[i + 1].first += (a[i] - 1);
        pre[i + 1].second += int(a[i] == 1);
    }

    for (; Q--; ) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        if (r - l == 1) {
            puts("NO");
            continue;
        }
        const auto& info = pre[r] - pre[l];
        puts(info.first >= info.second ? "YES" : "NO");
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