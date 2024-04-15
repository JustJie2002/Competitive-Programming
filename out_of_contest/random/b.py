import random

def work(p):
    n = len(p)
    for i in range(n):
        p[i] -= 1

    good = [i for i in range(n)]

    def power(p, pw2):
        if p == good:
            return 0
        pw2 += 1
        nxt = [0] * n
        for i in range(n):
            nxt[i] = p[p[i]]
        if nxt == good:
            return 1
        for pw in range(1, pw2):
            new_nxt = [-1] * n
            for i in range(n):
                nex = nxt[i]
                new_nxt[i] = nxt[nex]
            if new_nxt == good:
                return (1 << pw) - 1 + power(nxt, pw - 1)
            nxt, new_nxt = new_nxt, nxt
        return -1

    pw2 = 0
    while (1 << pw2) <= n:
        pw2 += 1

    return power(p, pw2)


N = 10 ** 5
p = [i + 1 for i in range(N)]
random.shuffle(p)
print(work(p))