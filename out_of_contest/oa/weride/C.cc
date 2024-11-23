/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 09.28.2024 11:44:03
*********************************************/

#ifdef BROKEN_CODE
#include <bits/LC_parser.h>
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

END = 2
INVIS = 1
NONE = 0

sys.setrecursionlimit(300000)
def solve(n, edges, vis):
    adj = [[] for _ in range(n)]

    for u, v in edges:
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)

    for i in range(len(vis)):
        vis[i] -= 1

    def dfs(cur, fa):
        ans = [0, int(cur in vis)]
        if cur == n - 1:
            ans[1] = END
        for nei in adj[cur]:
            if nei != fa:
                res = dfs(nei, cur)
                ans[0] += res[0]
                ans[1] = max(ans[1], res[1])
                if res[1] == INVIS:
                    ans[0] += 2
                elif res[1] == END:
                    ans[0] += 1
        return ans
    ans = dfs(0, -1)[0]
    return ans

#ifdef BROKEN_CODE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    exec(&Solution::LoveJenney); // CHANGE FOR PROBLEM
}
#endif

// ~ JustJie