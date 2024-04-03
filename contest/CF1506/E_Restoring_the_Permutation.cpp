/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.31.2024 23:42:38
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

    vector<int> q(n);
    set<int> mi, ma;
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
        mi.insert(i + 1);
        ma.insert(i + 1);
    }

    vector<int> p1(n);
    vector<int> p2(n);
    int pre = 0;
    for (int i = 0; i < n; i++) {
        int x = q[i];
        if (x != pre) {
            p1[i] = p2[i] = x;
            mi.erase(x);
            ma.erase(x);
        } else {
            p1[i] = *mi.begin();
            mi.erase(mi.begin());
            auto it = prev(ma.lower_bound(x));
            p2[i] = *it;
            ma.erase(it);
        }
        pre = x;
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", p1[i], " \n"[i == n - 1]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", p2[i], " \n"[i == n - 1]);
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