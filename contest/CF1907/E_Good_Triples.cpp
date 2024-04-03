/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.05.2023 11:01:31
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

    auto foo = [&](int x) -> int {
        int res = 0;
        while (x) {
            res += (x % 10);
            x /= 10;
        }
        return res;
    };

    int n_comb = foo(n) + n;
    map<int, int> freq;
    for (int a = 0; a <= n; a++) {
        int a_comb = foo(a) + a;
        if (a_comb <= n_comb) {
            freq[a_comb]++;
        }
    }

    printf("%zu\n", freq.size());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Jie ♥ Jenney