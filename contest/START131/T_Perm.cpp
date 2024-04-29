/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.24.2024 19:45:41
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

constexpr int M = 3;

void work(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    if (n % 3 == 0) {
        for (int i = 0; i < n; i += 3) {
            swap(p[i + 1], p[i + 2]);
        }
    } else if (n % 3 == 1) {
        reverse(p.begin(), p.end());
    } else {
        p[0] = 4;
        p[1] = 5;
        p[2] = 2;
        p[3] = 1;
        p[4] = 3;
        for (int i = 6; i <= n; i += 3) {
            p[i - 1] = i + 2;
            p[i] = i + 1;
            p[i + 1] = i;
        }
    }

    for (int x : p) {
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        work(t);
    }
}

// ~ Just Jie