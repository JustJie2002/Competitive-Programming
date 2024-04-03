
A = [1, 1, 2, 3]
B = [1, 2, 3]

N, M = len(A), len(B)

C = [0] * (N + M)

for i in range(N):
    for j in range(M):
        C[i + j + 1] = A[i] + B[j]

print(C)
