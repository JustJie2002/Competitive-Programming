/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.03.2023 15:39:05
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

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
using Point = pair<int, int>;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    vector<Point> p;
    for (int i = 0; i < n; i++) {
        p.emplace_back(a[i], a[n + i]);
    }

    i64 res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += (p[i + 1].first - p[i].first) + (p[i + 1].second - p[i].second);
    }

    printf("%lld\n", res);
    for (auto &[x, y] : p) {
        printf("%d %d\n", x, y);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney