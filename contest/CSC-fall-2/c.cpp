/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.18.2023 12:23:14
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

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    a.insert(a.begin(), 0);
    a.push_back(0);

    n += 2;

    i64 sum = accumulate(a.begin(), a.end(), 0LL);
    i64 pre = 0;
    for (int i = 0; i < n - 2; i++) {
        pre += a[i];
        if (pre == sum - pre - a[i + 1]) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney