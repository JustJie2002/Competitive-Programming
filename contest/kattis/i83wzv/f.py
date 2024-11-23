from collections import deque, defaultdict

def dfs(i,adj,visited,component):
    if visited[i]:return
    visited[i]=True
    component.append(i)
    for nei in adj[i]:
        dfs(nei,adj,visited,component)

def findCentroid(component,adj):
    queue = deque()
    degree = defaultdict(int)
    for comp in component:
        degree[comp] = len(adj[comp])
        if degree[comp] - 1 == 0:
            degree[comp] -= 1
            queue.append(comp)

    pre = []
    while queue:
        sz = len(queue)
        pre = []
        for _ in range(sz):
            u = queue.popleft()
            pre.append(u)

            for v in adj[u]:
                degree[v] -= 1
                if degree[v] == 1:
                    queue.append(v)
    return pre

n=int(input())
adj=[0]*(n+1)
for i in range(n+1):
    adj[i]=[]

for i in range(n):
    u,v=map(int,input().split())
    adj[u].append(v)
    adj[v].append(u)

components=[]
visited=[False]*(n+1)
for i in range(n+1):
    if not visited[i]:
        component=[]
        dfs(i,adj,visited,component)
        components.append(component)

centroids = []
for component in components:
    centroids.append(findCentroid(component,adj))