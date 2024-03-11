/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.18.2024 15:39:17
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
using Info = pair<int, int>;

void workout(int tc) {
    int n;
    scanf("%d", &n);

    vector<int> a(n), d(n);
    set<int> good;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        good.insert(i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    set<Info> pq;
    vector<Info> p(n);
    for (int i = 0; i < n; i++) {
        for (int di : {-1 : +1}) {
            int j = i + di;
            if (0 <= j && j < n) {
                a[i] -= d[i];
            }
        }
        pq.emplace(a[i], i);
    }

    for (int i = 0; i < n; i++) {
        int res = 0;
        vector<int> rem;
        while (!pq.empty()) {
            auto [dif, i] = *pq.begin();
            if (dif > 0) {
                break;
            }
            good.erase(i);
            rem.push_back(i);
        }
        if (good.empty()) {
            break;
        }
        for (int i : rem) {
            auto it = good.upper_bound(i);
            int L = -1, R = -1;
            if (it != s.end()) {
                R = *it;
            }
            if (it != s.begin()) {
                L = *prev(it);
            }
            if (L != -1) {
                a[L] -= 1;
            }
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

// ~ Just Jie