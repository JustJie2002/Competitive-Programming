/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.31.2023 13:53:10
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
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // skip or not skip
    // suppose we have <= x - 1, then how much can we benefit
    for (int i = 0; i < n; i++) {
        // suppose we only have a[i] - 1 left
        // so hard
        
    }
}