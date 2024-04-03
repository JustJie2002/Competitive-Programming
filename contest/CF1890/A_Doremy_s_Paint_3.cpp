/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 10.28.2023 10:36:05
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

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }

    int m = freq.size();

    if (m == 1) {
        printf("YES\n");
    } else if (m > 2) {
        printf("NO\n");
    } else {
        int a = freq.begin()->second;
        int b = freq.rbegin()->second;
        if (abs(a - b) <= 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
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