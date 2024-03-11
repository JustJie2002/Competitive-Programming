/***************************************************************************************************
 * author : Jie Chen
 * school : Rochester Institute of Technology
 * created: 10.16.2023 02:09:24
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void merge(set<int>& s, int a, int b) {
    int g = __gcd(a, b);
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            s.insert(i);
            s.insert(g / i);
        }
    }
}

void workout() {
    int a, b;
    scanf("%d%d", &a, &b);

    set<int> d{1, 2};
    merge(d, a, b - 2);
    merge(d, a - 2, b);
    merge(d, a - 1, b - 1);

    printf("%zu ", d.size());
    for (int x : d) {
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout();
    }
}

// ~ Jie ♥ Jenney