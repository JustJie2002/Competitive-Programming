/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.26.2023 20:53:00
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
    int cnt = 0;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
            cnt++;
        } else if (a[i] == 0) {
            zero = true;
        }
    }

    if (zero || (cnt & 1)) {
        printf("0\n");
    } else {
        printf("1\n");
        printf("1 0\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}