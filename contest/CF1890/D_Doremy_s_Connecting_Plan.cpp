/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.28.2023 11:39:33
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
using Pair = pair<i64, i64>;

void workout(int tc) {
    int n, c;
    scanf("%d%d", &n, &c);

    vector<Pair> p;
    i64 cur_sum = 0;
    for (int i = 0; i < n; i++) {
        i64 x;
        scanf("%lld", &x);
        if (i == 0) {
            cur_sum = x;
        } else {
            p.emplace_back(1LL * (i + 1) * c - x, x);
        }
    }

    sort(p.begin(), p.end());

    for (auto &[k, x] : p) {
        if (k <= 0) {
            cur_sum += x;
        } else {
            if (cur_sum >= k) {
                cur_sum += x;
            } else {
                printf("NO\n");
                return;
            }
        }
    }

    printf("YES\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney