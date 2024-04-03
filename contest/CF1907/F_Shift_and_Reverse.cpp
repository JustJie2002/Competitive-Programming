/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.05.2023 11:21:10
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

constexpr int inf = 1e9 + 5;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    int mi = inf, ma = -inf;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
    }

    if (mi == ma) {
        puts("0");
        return;
    }

    int pivot = 0;
    while (pivot < n && a[pivot] != ma || (a[(pivot + 1) % n] == ma && a[(pivot - 1 + n) % n] == ma)) {
        pivot++;
    }

    assert(pivot != n);

    int ptra = pivot, ptrb = pivot;
    for (int i = 0; i < n - 1; i++) {
        ptra = (ptra + 1) % n;
        ptrb = (ptrb - 1 + n) % n;
        
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