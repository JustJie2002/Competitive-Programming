"""
Problem Statement: 

Given a string s of lowercase English characters, the following operation can be performed on it any number of times.
- Choose three consecutive characters s[i], s[i+1] and s[i+2] 
  where (0 <= i <= len(s) - 1, 0-based indexing) such that s[i] = s[i+1] and s[i+1] != s[i+2]. Replace s[i+2] with s[i].
- For example, if s = "aabc", then after the operation at 1 = 1, s = "aaac".
Find the maximum number of operations that can be applied to s.

Input: "aabba"
Output: 4
Explanation:
aabba
1. aabbb
2. aaabb
3. aaaab
4. aaaaa
"""
from itertools import groupby

def work(s: str):
    stack = []

    grouped = []
    ans = 0
    for c, grp in groupby(s):
        grouped.append((c, len(list(grp))))

    for char, count in reversed(grouped):
        while stack and count > 1:
            if stack[-1][0] != char:
                ans += stack[-1][1]
            count += stack[-1][1]
            stack.pop()
        stack.append((char, count))
    
    return ans

assert work("aabba") == 4