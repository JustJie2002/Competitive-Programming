from math import *

vs = [89,59,43,13,173,47,103]
a = 3
q = 11
qrem = q % (4 * a)

ans = []
for p in vs:
    prem = p % (4 * a)
    if gcd(p, a) != 1:
        continue
    print(qrem, prem, p)
    # if qrem == prem or q