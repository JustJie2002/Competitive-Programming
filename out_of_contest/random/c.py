"""
author : Jie Chen (4th Year CS)
school : Rochester Institute of Technology
created: 10.09.2024 17:17:57
"""

D = 10

def solution(s):
    freq = [0] * D

    for c in s:
        freq[int(c)] += 1

    res = ""
    center = ""
    for d in range(D - 1, -1, -1):
        if freq[d] == 0:
            continue
        use = freq[d] // 2
        if d == 0:
            if res:
                res += use * str(d)
                freq[d] -= use
        else:
            res += use * str(d)
            freq[d] -= use
        if not center and freq[d]:
            center = str(d)

    return res + center + res[::-1]

print(solution("39878"))
print(solution("00900"))
print(solution("0000"))
print(solution("54321"))


# ~ JustJie