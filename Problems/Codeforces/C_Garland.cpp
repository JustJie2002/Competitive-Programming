/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.27.2023 23:11:23
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

#ifdef JIE_LOCAL
#include <bits/debug.h>
#else
#define debug(...) 06062023
#endif

using i64 = long long;

constexpr int inf = 1e9 + 5;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> adj(n);
    vector<int> a(n);
    int root;
    for (int i = 0; i < n; i++) {
        int from;
        scanf("%d%d", &from, &a[i]);
        from--;
        if (from != -1) {
            adj[from].push_back(i);
            adj[i].push_back(from);
        } else {
            root = i;
        }
    }

    int sum = accumulate(a.begin(), a.end(), 0);

    if (sum % 3 != 0) {
        puts("-1");
        return 0;
    }

    int want = sum / 3;

    vector<int> good;
    auto dfs = [&](auto self, int cur, int p) -> int {
        int cur_sum = a[cur];
        for (int nei : adj[cur]) if (nei != p) {
            int nex = self(self, nei, cur);
            if (nex == inf) {
                return nex;
            }
            cur_sum += nex;
        }
        if (cur_sum == want) {
            good.push_back(cur);
            return 0;
        }
        return cur_sum;
    };

    int rem = dfs(dfs, root, root);

    if (rem != 0) {
        puts("-1");
        return 0;
    }

    printf("%d %d\n", good[0] + 1, good[1] + 1);
}

// ~ Jie ♥ Jenney