def Solve(mat):
    k = len(mat)
    
    dp = [0] * k
    
    current = 0
    
    # maximum of left ro right on top row
    for j in range(k):
        if j + 1 < k:
            dp[j] = max(dp[j], current + mat[0][j+1])
        else:
            dp[j] = max(dp[j], current)
        
        if 0 <= j - 1:
            current = max(mat[0][j-1], current)
    
    current = 0
    
    # maximum of right to left on top row
    for j in reversed(range(k)):
        if 0 <= j - 1:
            dp[j] = max(dp[j], current + mat[0][j-1])
        else:
            dp[j] = max(dp[j], current)
        
        if j + 1 < k:
            current = max(mat[0][j+1], current)
    
    # calculate the drop for each row.
    for i in range(1, k):
        for j in range(k):
            if 0 <= j - 1 and j + 1 < k:
                dp[j] = mat[i][j-1] + dp[j] + mat[i][j+1]
            elif 0 <= j - 1:
                dp[j] = mat[i][j-1] + dp[j]
            elif j + 1 < k:
                dp[j] = dp[j] + mat[i][j+1]
            else:
                dp[j] = dp[j]
    
    return max(dp)

mat = [
    [1, 0, 0, 1],
    [1, 0, 0, 1],
    [1, 0, 0, 1],
    [1, 1, 1, 1],
]

print(Solve(mat))