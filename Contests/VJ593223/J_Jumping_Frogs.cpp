/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.08.2023 18:40:44
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

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    vector<int> good;
    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] > b[j]) {
            good.push_back(i);
            j++;
        }
    }

    printf("%zu\n", good.size());
    for (int x : good) {
        printf("%d ", x);
    }
}

// ~ Jie ♥ Jenney