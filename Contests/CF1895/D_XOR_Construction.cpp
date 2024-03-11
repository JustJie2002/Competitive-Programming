/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.04.2023 01:31:32
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

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

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &b[i]);
    }

    vector<int> pre(n);
    for (int i = 0; i < n - 1; i++) {
        pre[i + 1] = pre[i] ^ b[i];
    }

    debug(pre);

    // vector<int> marked(n, -1);
    // for (int i = 0; i < n; i++) {
    //     int j = Xor ^ i;
    //     debug(i, j);
    //     marked[i] = i;
    //     bool ch = true;
    //     int p = i;
    //     for (int x : b) {
    //         p = x ^ p;
    //         if (p >= n || marked[p] == i) {
    //             ch = false;
    //             break;
    //         }
    //         marked[p] = i;
    //     }
    //     if (ch) {
    //         int p = i;
    //         printf("%d ", i);
    //         for (int x : b) {
    //             p = x ^ p;
    //             printf("%d ", p);
    //         }
    //         break;
    //     }
    // }
}

// ~ Jie ♥ Jenney