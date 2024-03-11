/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.30.2023 01:15:26
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

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<int> good(n), good2(n);
    good[0] = 1;
    int ma = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > ma) {
            good[i] = 1;
        }
        ma = max(ma, a[i]);
    }
    good2[n - 1] = 1;
    int mi = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < mi) {
            good2[i] = 1;
        }
        mi = min(mi, a[i]);
    }

    vector<int> res;
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (good[i] && good2[i]) {
            if (m < 100) {
                res.push_back(a[i]);
            }
            m++;
        }
    }

    printf("%d ", m);
    for (int x : res) {
        printf("%d ", x);
    }
}

// ~ Jie ♥ Jenney