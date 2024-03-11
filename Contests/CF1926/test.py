
LIM = 2 * (10 ** 5) + 1

def sumd(d):
    d = str(d)
    res = 0
    for c in d:
        res += int(c)
    return res

with open("out.txt", "w") as fp:
    fp.write("{")
    ans = 0
    for i in range(1, LIM):
        ans += sumd(i)
        fp.write(str(ans) + ",")
    fp.write("}")