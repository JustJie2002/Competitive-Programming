/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.22.2024 01:04:02
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

    map<int, vector<int>> groups;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        groups[x].push_back(i);
    }

    vector<int> ans;
    for (const auto& [x, pos] : groups) {
        int m = pos.size();
        bool good = false;
        for (int i = 0; i < m - 1; i++) {
            if (pos[i] + 1 == pos[i + 1]) {
                good = true;
                break;
            }
            if (pos[i] + 2 == pos[i + 1]) {
                good = true;
                break;
            }
        }
        if (good) {
            ans.push_back(x);
        }
    }

    if (ans.empty()) {
        puts("-1");
    } else {
        int m = ans.size();
        for (int i = 0; i < m; i++) {
            printf("%d%c", ans[i], " \n"[i == m - 1]);
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