
from collections import deque
import sys

DIRS = [(-1, 0), (0, -1), (1, 0), (0, 1)]
def good(global_vis, start, end, ROW, COL):
    if start in global_vis:
        return False
    if end in global_vis:
        return False
    visited = set()

    def check(r, c):
        return 0 <= r < ROW and 0 <= c < COL and (r, c) not in visited and (r, c) not in global_vis

    bfs = deque([start])
    while bfs:
        r, c = bfs.popleft()
        if (r, c) == end:
            return True
        for dr, dc in DIRS:
            nr = r + dr
            nc = c + dc
            if check(nr, nc):
                bfs.append((nr, nc))
                visited.add((nr, nc))
    return False

sys.setrecursionlimit(300000)
def findMaximumDistance(grid):
    ROW = len(grid)
    COL = len(grid[0])

    obstacles = []
    for i in range(ROW):
        for j in range(COL):
            if grid[i][j] == 'S':
                start = (i, j)
            if grid[i][j] == 'E':
                end = (i, j)
            if grid[i][j] == '*':
                obstacles.append((i, j))

    global_vis = set()
    bad = deque()
    for i, j in obstacles:
        bad.append((i, j))
        global_vis.add((i, j))

    def walk():
        current_layer = len(bad)
        while current_layer:
            r, c = bad.popleft()

            for dr, dc in DIRS:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < ROW and 0 <= nc < COL and (nr, nc) not in global_vis:
                    bad.append((nr, nc))
                    global_vis.add((nr, nc))

            current_layer -= 1

    current_distance = 1
    while True:
        if not good(global_vis, start, end, ROW, COL):
            break
        walk()
        current_distance += 1
    return current_distance - 1

# grid = [
#     "S..*",
#     "..*.",
#     "....",
#     "...E"
# ]
grid = [
    "..*",
    ".S.",
    "..*",
    "...",
    "..E"
]
print(findMaximumDistance(grid))