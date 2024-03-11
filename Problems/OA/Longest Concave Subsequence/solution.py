from typing import *
from sortedcontainers import *

def solve(a: List[int]):
    a = [-x for x in a]

    pos = SortedDict()
    for i, x in enumerate(a):
        if x not in pos:
            pos[x] = []
        pos[x].append(i)

    ans = m = 0
    sl = SortedList()
    for ids in pos.values():
        for ind in ids:
            sl.add(ind)
            m += 1
        for ind in ids:
            L = sl[0]
            R = sl[-1]
            if L < ind:
                not_less = sl.bisect_left(ind) - 1
                ans = max(ans, ind - L + 1 - not_less)
            if R > ind:
                not_less = m - sl.bisect_right(ind) - 1
                ans = max(ans, R - ind + 1 - not_less)
    
    return ans

print(solve([3, 1, 4, 2, 5]))