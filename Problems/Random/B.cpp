/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.15.2024 13:29:03
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> freq;
        int acc = 0;
        for (int j = i; j < n; j++) {
            int x = a[j];
            freq[x]++;
            if (freq[x] == 1) {
                acc++;
            }
            if (freq[x] == k) {
                acc--;
            }
            if (acc == 0) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    printf("%d\n", ans);
}

// ~ Just Jie