import heapq
from itertools import *

n = int(input())
a = [*map(int, input().split())]
a.sort()

pq = []
for x, g in groupby(a):
    heapq.heappush(pq, (x, len(list(g))))

ans = 0
while pq:
    x, f = heapq.heappop(pq)
    while pq and pq[0][0] == x:
        f += pq[0][1]
        heapq.heappop(pq)
    ans = max(ans, x)
    f >>= 1
    if f:
        heapq.heappush(pq, (x << 1, f))

print(ans)