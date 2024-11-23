import sys
END = 2
INVIS = 1
NONE = 0

sys.setrecursionlimit(300000)
# def solve(n, edges, vis):
#     adj = [[] for _ in range(n)]

#     for u, v in edges:
#         u -= 1
#         v -= 1
#         adj[u].append(v)
#         adj[v].append(u)

#     for i in range(len(vis)):
#         vis[i] -= 1
#     vis = set(vis)

#     def dfs(cur, fa):
#         ans = [0, int(cur in vis)]
#         if cur == n - 1:
#             ans[1] = END
#         for nei in adj[cur]:
#             if nei != fa:
#                 res = dfs(nei, cur)
#                 ans[0] += res[0]
#                 ans[1] = max(ans[1], res[1])
#                 if res[1] == INVIS:
#                     ans[0] += 2
#                 elif res[1] == END:
#                     ans[0] += 1
#         return ans
#     ans = dfs(0, -1)[0]
#     return ans

def solve(n, edges, vis):
    lst = []
    for i in range(n):
        lst.append([])
    for i, j in edges:
        i = i - 1
        j = j - 1
        lst[i].append(j)
        lst[j].append(i)
    
    for i in range(len(vis)):
        vis[i] = vis[i] - 1
    
    def dfs(c, f):
        result = [0, int(c in vis)]
        if c == n - 1:
            result[1] = END
        for i in lst[c]:
            if i != f:
                res = dfs(i, c)
                result[0] = result[0] + res[0]
                result[1] = max(result[1], res[1])
                if res[1] == INVIS:
                    result[0] = result[0] + 2
                elif res[1] == END:
                    result[0] = result[0] + 1
        return result
    final = dfs(0, -1)[0]
    return final

n = 3
edges = [(1, 2), (1, 3)]
vis = [2]
print(solve(n, edges, vis))