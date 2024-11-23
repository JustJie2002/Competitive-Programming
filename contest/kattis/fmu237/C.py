from sortedcontainers import SortedList
from math import inf

n = int(input())
a = [int(input()) for _ in range(n)]

mx = max(a)
mxi = a.index(mx)
a.pop(mxi)
m = n - 1
pre = [0] * (m + 1)
sl = SortedList()
for i, x in enumerate(a):
    pre[i + 1] = pre[i]
    g = sl.bisect_right(x)
    sl.add(x)
    pre[i + 1] += (i - g)

suf = [0] * (m + 1)
sl2 = SortedList()
for i in range(m - 1, -1, -1):
    x = a[i]
    suf[i] = suf[i + 1]
    g = sl2.bisect_right(x)
    sl2.add(x)
    suf[i] += (m - i - 1) - g

ans = inf
for i in range(n):
    res = abs(mxi - i)
    res += pre[i]
    res += suf[i]
    ans = min(ans, res)
print(ans)