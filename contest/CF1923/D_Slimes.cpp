/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.24.2024 03:50:58
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

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    auto work = [&]() -> vector<int> {
        vector<int> res(n);
        // TODO
        

        return res;
    };

    auto L = work();
    reverse(a.begin(), a.end());
    auto R = work();

    for (int i = 0; i < n; i++) {
        int res = min(L[i], R[i]);
        if (res == n) {
            res = -1;
        }
        printf("%d%c", res, " \n"[i == n - 1]);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; T--; t++) {
        workout(t);
    }
}

// ~ Just Jie