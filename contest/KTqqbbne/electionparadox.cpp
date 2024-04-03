/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.18.2023 20:44:05
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

    sort(a.rbegin(), a.rend());

    int win = 0;
    if (n % 2 == 1) {
        for (int i = 0; i < n / 2; i++) {
            win += a[i];
        }
        for (int i = n / 2; i < n; i++) {
            win += (a[i] - 1) / 2;
        }
    } else {
        for (int i = 0; i < n / 2 - 1; i++) {
            win += a[i];
        }
        for (int i = n / 2 - 1; i < n; i++) {
            win += (a[i] - 1) / 2;
        }
    }
    printf("%d\n", win);
}