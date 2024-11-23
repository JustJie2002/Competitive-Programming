import sys
from collections import deque

input = sys.stdin.readline

PARTS = "0123456789abcdef"

R, C = map(int, input().split())
G = [input().strip() for _ in range(R)]

snake = []
for r in range(R):
    for c in range(C):
        p = G[r][c]
        if p == 'A':
            A = (r, c)
        elif p in PARTS:
            snake.append((PARTS.index(p), (r, c)))

snake.sort()
size = len(snake)
if size == 1:
    print(1)
    sys.exit()

