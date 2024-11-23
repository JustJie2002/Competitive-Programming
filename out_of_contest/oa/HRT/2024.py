"""
author : Jie Chen (4th Year CS)
school : Rochester Institute of Technology
created: 09.06.2024 21:06:39
"""

BOARD_SIZE = 4

def work(operations):   
    board = [[0] * BOARD_SIZE for _ in range(BOARD_SIZE)]

    def perform_move(direction):
        # stack[-1] - [val, can_combine]
        match direction:
            case "L":
                for r in range(BOARD_SIZE):
                    stack = []
                    for x in board[r]:
                        if x != 0:
                            if not stack:
                                stack.append([x, True])
                            else:
                                if stack[-1][0] == x and stack[-1][1]:
                                    stack[-1][0] *= 2
                                    stack[-1][1] = False
                                else:
                                    stack.append([x, True])
                    for c in range(BOARD_SIZE):
                        if c < len(stack):
                            board[r][c] = stack[c][0]
                        else:
                            board[r][c] = 0

            case "R":
                for r in range(BOARD_SIZE):
                    stack = []
                    for x in board[r][::-1]:
                        if x != 0:
                            if not stack:
                                stack.append([x, True])
                            else:
                                if stack[-1][0] == x and stack[-1][1]:
                                    stack[-1][0] *= 2
                                    stack[-1][1] = False
                                else:
                                    stack.append([x, True])
                    for c in range(BOARD_SIZE - 1, -1, -1):
                        if BOARD_SIZE - c - 1 < len(stack):
                            board[r][c] = stack[BOARD_SIZE - c - 1][0]
                        else:
                            board[r][c] = 0

            case "U":
                for c in range(BOARD_SIZE):
                    stack = []
                    for r in range(BOARD_SIZE):
                        x = board[r][c]
                        if x != 0:
                            if not stack:
                                stack.append([x, True])
                            else:
                                if stack[-1][0] == x and stack[-1][1]:
                                    stack[-1][0] *= 2
                                    stack[-1][1] = False
                                else:
                                    stack.append([x, True])
                    for r in range(BOARD_SIZE):
                        if r < len(stack):
                            board[r][c] = stack[r][0]
                        else:
                            board[r][c] = 0

            case "D":
                for c in range(BOARD_SIZE):
                    stack = []
                    for r in range(BOARD_SIZE - 1, -1, -1):
                        x = board[r][c]
                        if x != 0:
                            if not stack:
                                stack.append([x, True])
                            else:
                                if stack[-1][0] == x and stack[-1][1]:
                                    stack[-1][0] *= 2
                                    stack[-1][1] = False
                                else:
                                    stack.append([x, True])
                    for r in range(BOARD_SIZE -1, -1, -1):
                        if BOARD_SIZE - r - 1 < len(stack):
                            board[r][c] = stack[BOARD_SIZE - r - 1][0]
                        else:
                            board[r][c] = 0

    for operation in operations:
        direction, c, r, val = operation.split()
        r = int(r)
        c = int(c)
        val = int(val)
        perform_move(direction)
        if board[r][c] != 0:
            return "Error"
        board[r][c] = val
    
    rows = []
    for row in board:
        cols = []
        for x in row:
            if x != 0:
                cols.append(str(x))
            else:
                cols.append(".")
        rows.append(",".join(cols))
    return "\n".join(rows)

operations = [
    "L 2 3 4",
    "U 1 3 4",
    "U 0 0 2",
    "R 3 2 2"
]

print(work(operations))

# ~ JustJie