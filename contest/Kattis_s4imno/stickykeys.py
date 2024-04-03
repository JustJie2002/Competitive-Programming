from itertools import groupby

s = input()

t = []
for c, g in groupby(s):
    t.append(c)

print("".join(t))