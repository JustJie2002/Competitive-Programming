"""
author : Jie Chen (4th Year CS)
school : Rochester Institute of Technology
created: 10.09.2024 17:11:42
"""

P = [2, 3, 5, 8, 13, 12, 7, 10, 8, 9, 17, 17, 16, 15, 13, 10, 5, 6, 11, 8, 10, 9, 10, 10]
N = len(P)

def solution(n):
    if n == 0:
        return 0
    if n <= 2:
        return 1
    n -= 3
    return P[n % N]

print(solution(2))
print(solution(6))
print(solution(10))

# ~ JustJie