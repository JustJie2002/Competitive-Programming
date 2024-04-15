/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 10:44:46
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

int main() {
    int p, q;
    scanf("%d%d", &p, &q);

    for (int i = 0; i < p; i++) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i]);
        }
        vector<int> dead(m, 1);
        for (int j = m - 1; j >= 0; j--) {
            for (int k = 0; k < q; k++) {
                if (j + k >= m) {
                    break;
                }
                if (j + k + a[i] > m) {
                    dead[j] |= 2;
                } else if (j + k + a[i] == m) {
                    dead[j] |= 1;
                } else {
                    dead[j] |= (1 << dead[j + k + a[i]]);
                }
            }
        }

    }

    bool win = false;


    puts(win ? "Alice can win." : "Bob will win.");
}

// ~ Just Jie